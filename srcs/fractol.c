/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/24 17:32:44 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Julia , Mandelbrot
#include "../headers/fractol.h"


/*
    
        (1920,1080)    
     _________________ 
    |.                |
    |                 | 
    |                 |
    |                 |
    |                 |
    |_________________|

          (-2,2)
     _________________
    |                 |
    |     ..          |
    |   .... ....     |  
    | ....      .. .  |
    |     .....       |
    |_________________|
*/

int main()  // usage : ./fractol name x y 
{
    void *mlx;
    void *window;
    t_complex z;
    t_complex c;
    double x_tmp; 
    int x;
    int y;
    int iter;
    int color;
    
    x = 0;
    y = 0; 
    mlx = mlx_init();
    if (!mlx)
        return MLX_FAIL;
    window = mlx_new_window(mlx, LENGTH, WIDTH, "Julia Set");
    if (!window)
        return NEW_WIN_FAIL;
    while (y < WIDTH) 
        {
            x = 0;
            while (x < LENGTH)
            {
                z.x = 0;
                z.y = 0;
                iter = 0;
                c.x = map(x,-2,2,LENGTH);
                c.y = map(y,-2,2,WIDTH);
                printf("x --> |%d| ---> |%f|\n",x,c.x);
                while ((z.x * z.x) + (z.y * z.y) <= pow(2,2) && iter < MAX_ITER) 
                {
                    x_tmp = pow(z.x,2) - pow(z.y,2);
                    z.y = 2 * z.x * z.y + c.y;
                    z.x = x_tmp + c.x;
                    iter++;
                }
               color =  iter / MAX_ITER;
               if (color)
               {
                 color = RED;
                mlx_pixel_put(mlx, window, x, y, color);
               }
                x++;
            }
            y++;
        }
    mlx_loop(mlx);
    return 0;
    
}