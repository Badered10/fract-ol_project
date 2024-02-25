/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/25 10:13:12 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Julia , Mandelbrot
#include "../headers/fractol.h"

void check_pixel(void * mlx, void* window,int x, int y)
{
    t_complex z;
    t_complex c;
    int iter;
    double x_tmp;
    int color;

    z.x = 0;
    z.y = 0;
    iter = 0;
    c.x = map(x,-2,2,LENGTH);
    c.y = map(y,-2,2,WIDTH); 
    while ((z.x * z.x) + (z.y * z.y) <= pow(2,2) && iter < MAX_ITER) 
    {
        x_tmp = pow(z.x,2) - pow(z.y,2);
        z.y = 2 * z.x * z.y + c.y;
        z.x = x_tmp + c.x;
        iter++;
    }
    if ((z.x * z.x) + (z.y * z.y) > pow(2,2))
    {
        color = map(iter,BLACK,WHITE,MAX_ITER);
        mlx_pixel_put(mlx, window, x, y, color);
    }
    else
        mlx_pixel_put(mlx, window, x, y, CYAN);
}

void render_fractal(void *mlx, void *window)
{
    int x;
    int y;

    x = 0;
    y = 0;
     while (y < WIDTH)
        {
            x = 0;
            while (x < LENGTH)
            {
                check_pixel(mlx, window, x, y);
                x++;
            }
            y++;
        }
}

int main()  // usage : ./fractol name x y 
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    if (!mlx)
        return MLX_FAIL;
    window = mlx_new_window(mlx, LENGTH, WIDTH, "Julia Set");
    if (!window)
        return NEW_WIN_FAIL;
    render_fractal(mlx, window);
    mlx_loop(mlx);
    return 0;
}

/*
    
        x (0,1920)
        y (0,1080) 
    0_________________1920 (100,y)
    |.                |
    |                 | 
    |                 |
    |                 |
    |                 |
    |_________________|
    1080
          x(-2,2)
          y(-2,2)    
     _________________
    |                 |
    |     ..          |
    |   .... ....     |  
    | ....      .. .  |
    |     .....       |
    |_________________|
*/