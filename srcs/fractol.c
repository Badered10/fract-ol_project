/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/27 21:15:05 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Julia , Mandelbrot
#include "../headers/fractol.h"

static void which_fractal(t_fractal *fractal, char **argv)
{
    if (fractal->check_set == 10)
    {
        fractal->c.x = (map(fractal->x,-2,2,LENGTH) * fractal->zoom_value) + (fractal->zoom_value * fractal->shift_value);
        fractal->c.y = (map(fractal->y,2,-2,WIDTH) * fractal->zoom_value);
        fractal->z.x = 0;
        fractal->z.y = 0; 
    }
    else if (fractal->check_set == 20)
    {
            fractal->z.x = map(fractal->x,-2,2,LENGTH) * fractal->zoom_value;
            fractal->z.y = map(fractal->y,2,-2,WIDTH) * fractal->zoom_value;
            if (fabs(check_valid_float(argv[2])) + fabs(check_valid_float(argv[3])) > 4)
            {
                ft_printf("Julia range is (-2,2) !\n");
                exit(1);
            }
            fractal->c.x = check_valid_float(argv[2]);
            fractal->c.y = check_valid_float(argv[3]);
    }
    fractal->iter = 0;
}

static void	pixel_image_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

static void check_pixel(t_fractal *fractal , t_img *img, char **argv)
{
    which_fractal(fractal,argv);
    while (pow(fractal->z.x,2) + pow(fractal->z.y,2) <= 4
            && fractal->iter < MAX_ITER)
    {
        fractal->x_tmp = pow(fractal->z.x,2) - pow(fractal->z.y,2); // x = x^2 - y^2 
        fractal->z.y = 2 * fractal->z.x * fractal->z.y + fractal->c.y; //y = 2.x.y + c
        fractal->z.x = fractal->x_tmp + fractal->c.x;
        (fractal->iter)++;
    } 
    if (pow(fractal->z.x,2) + pow(fractal->z.y,2) > 4) 
    {
        fractal->color = map(fractal->iter,0x05FFFF,CYAN,MAX_ITER);
        pixel_image_put(img,fractal->x,fractal->y,fractal->color);
    }
    else
       pixel_image_put(img,fractal->x,fractal->y, BLACK);
}
static void render_fractal(t_fractal *fractal, char **argv)
{
    t_img img;
    
    img.img = mlx_new_image(fractal->mlx,WIDTH + 1,LENGTH + 1);
    fractal->img = img;
    img.addr = mlx_get_data_addr(img.img,&img.bpp,&img.line_length,&img.endian);
    fractal->y = 0;
     while (fractal->y <= WIDTH)
        {
            fractal->x = 0;
            while (fractal->x <= LENGTH)
            {
                check_pixel(fractal, &img, argv);
                (fractal->x)++;
            }
            (fractal->y)++;
        }
    mlx_put_image_to_window(fractal->mlx,fractal->win,fractal->img.img,0,0);
    mlx_string_put(fractal->mlx, fractal->win, 0, 0,BLACK,fractal->by_me);
}
int mouse_hook(int button,int x,int y,t_fractal *param)
{
    (void)x;
    (void)y;
    if (button == 5)
        param->zoom_value *= 0.95;
    else if (button == 4)
         param->zoom_value *= 1.05;
    else if (button == 2)
        param->shift_value -= 0.5;
    else if (button == 1)
        param->shift_value += 0.5;
    render_fractal(param, param->argv);
    return(1);
}

static void syntax_err(int id, char *arg )
{
    if (!ft_strncmp(arg,"help",ft_strlen(arg)))
    {
        ft_printf("\t[Help Menu]\nSyntax must be : as folow: ./fractol fractal");
        ft_printf("_name\nIn julia fractal you must enter x and y after name\n");
        ft_printf("Supported fracts:\nM --> Mendlebort Set\nJ --> Julia Set\n");
        exit(0);
    }
    else if (!id)
        ft_printf("You enterd unsupported fractal\nFor mor infos enter './farctol help'");
    else if (id == 20 || id == 10 || id == 30)
         ft_printf("Syntax Error \nFor mor infos enter './farctol help'");
    exit(1);
}
static int check_arg_set(char **argv, int argc , t_fractal *fractal)
{
      if (argc < 2)
        syntax_err(0, "help");
    if (ft_strlen(argv[1]) != 1)
        syntax_err(0,argv[1]);
    if (argv[1][0] == 'm' || argv[1][0] == 'M')
    {
        if (argc != 2) // ./fractal M
            syntax_err(10,argv[1]);
        fractal->name = "Mandelbrot Set";
        fractal->by_me = "Mandelbrot Set By baouragh";
        return (10);
    }
    else if (argv[1][0] == 'j' || argv[1][0] == 'J')
    {
        if (argc != 4) // ./fractal J x y
            syntax_err(20,argv[1]);
            fractal->name = "Julia Set";
            fractal->by_me = "Julia Set By baouragh";
        return (20);
    }
    else if (argv[1][0] == 's' || argv[1][0] == 'S') // TO DO Sierpinski Gasket;
        return (30);
    syntax_err(0, "help");
    return (0);
}
 
int main(int argc, char **argv)  // usage : ./fractol name x y 
{
    t_fractal fractal;

    fractal.argv = argv;
    fractal.argc = argc;
    fractal.zoom_value = 1;
    fractal.shift_value = 0;
    fractal.check_set = check_arg_set(argv,argc, &fractal);
    fractal.mlx = mlx_init();
    if (!fractal.mlx)
        return (MLX_FAIL);
    fractal.win = mlx_new_window(fractal.mlx, LENGTH, WIDTH, fractal.name);
    if (!fractal.win)
        return NEW_WIN_FAIL;
    render_fractal(&fractal, argv);
    mlx_mouse_hook (fractal.win, mouse_hook , &fractal);
    mlx_loop(fractal.mlx);
    return 0;
}

