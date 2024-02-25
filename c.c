#include "headers/fractol.h"



int main ()
{
    t_fractal test;
    t_img img;

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
    
}