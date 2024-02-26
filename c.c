#include "headers/fractol.h"

void	pixel_image_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void check_pixel(t_fractal *fractal , t_img *img)
{
    fractal->iter = 0;
    fractal->z.x = map(fractal->x,-2,2,LENGTH);
    fractal->z.y = map(fractal->y,2,-2,WIDTH);

    fractal->c.x = -0.8;
    fractal->c.y = 0.156;
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

    ft_printf("hello father\n");
    exit(111);
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
