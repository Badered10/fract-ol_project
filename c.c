#include "headers/fractol.h"

void	pixel_image_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int main ()
{
    t_fractal test;
    t_img img;

    int x;
    int y;

    y = 0;

    test.mlx = mlx_init();
    if (!test.mlx)
        ft_putstr_fd("error occur in malloc\n",2);
    test.win = mlx_new_window(test.mlx,LENGTH,WIDTH,"test window");
    if (!test.win)
        ft_putstr_fd("error occur in malloc\n",2);
    img.img = mlx_new_image(test.mlx,WIDTH,LENGTH);
    if (!img.img)
        ft_putstr_fd("error occur in malloc\n",2);
    img.addr = mlx_get_data_addr(img.img,&img.bpp,&img.line_length,&img.endian);
    
    while (y < WIDTH)
    {
        x = 0;
        while (x < LENGTH / 2)
            pixel_image_put(&img, x++,y, CYAN);
            y++;
    }
    mlx_put_image_to_window(test.mlx,test.win,img.img,0,0);
    mlx_loop(test.mlx);
}