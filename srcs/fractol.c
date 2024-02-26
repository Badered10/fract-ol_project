/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/26 21:35:10 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Julia , Mandelbrot
#include "../headers/fractol.h"

// void syntax_err(int id)
// {
//     if (!id)
//     {
        
//     }
        
// }

// int check_arg_set(char **argv, int argc, t_fractal fractal)
// {
//     if (ft_strlen(argv[1]) != 1)
//         syntax_err(0); // TO DO !! exit(1);
//     if (argv[1][0] == 'm' || argv[1][0] == 'M')
//     {
//         if (argc != 2) // ./fractal M
//             syntax_err(10);
//         return (10);
//     }
//     else if (argv[1][0] == 'j' || argv[1][0] == 'J')
//     {
//         if (argc != 4) // ./fractal J x y
//             syntax_err(20);
//         check_valid_xy(argv[2],argv[3]); // TO DO
//         return (20);
//     }
//     else if (argv[1][0] == 's' || argv[1][0] == "S") // TO DO Sierpinski Gasket;
//         return (30);
// }

void	pixel_image_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void check_pixel(t_fractal *fractal , t_img *img)
{
    fractal->z.x = 0;
    fractal->z.y = 0;
    fractal->iter = 0;
    fractal->c.x = map(fractal->x,-2,2,LENGTH);
    fractal->c.y = map(fractal->y,2,-2,WIDTH);
    // fractal->y = 0.8;
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
        fractal->color = map(fractal->iter,BLACK,WHITE,MAX_ITER);
        pixel_image_put(img,fractal->x,fractal->y,fractal->color); 
    }
    else
       pixel_image_put(img,fractal->x,fractal->y, ORANGE);
}
void render_fractal(t_fractal *fractal, t_img *img)
{
    fractal->y = 0;
     while (fractal->y <= WIDTH)
        {
            fractal->x = 0;
            while (fractal->x <= LENGTH)
            {
                check_pixel(fractal,img);
                (fractal->x)++;
            }
            (fractal->y)++;
        }
}
 
int main()  // usage : ./fractol name x y 
{
    t_fractal fractal;
    t_img img;

    // fractal.check_set = check_arg_set(argv,argc,fractal);
    // if (fractal.check_set < 0)
    //     return (SYNTAX_ERR);
    fractal.mlx = mlx_init();
    if (!fractal.mlx)
        return (MLX_FAIL);
    fractal.win = mlx_new_window(fractal.mlx, LENGTH, WIDTH, "Mandelbrot Set");
    if (!fractal.win)
        return NEW_WIN_FAIL;
    img.img = mlx_new_image(fractal.mlx,WIDTH + 1,LENGTH + 1);
    img.addr = mlx_get_data_addr(img.img,&img.bpp,&img.line_length,&img.endian);
    render_fractal(&fractal,&img);
    mlx_put_image_to_window(fractal.mlx,fractal.win,img.img,0,0);
    mlx_string_put(fractal.mlx, fractal.win, 0, 0,BLACK,"Mandelbrot By baouragh");
    mlx_loop(fractal.mlx);
    return 0;
}
