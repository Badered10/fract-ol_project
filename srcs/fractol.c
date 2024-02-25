/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/25 10:53:41 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Julia , Mandelbrot
#include "../headers/fractol.h"

void check_pixel(t_fractal *fractal)
{
    printf("y --> |%d|\n",fractal->y);
    fractal->z.x = 0;
    fractal->z.y = 0;
    fractal->iter = 0;
    fractal->c.x = map(fractal->x,-2,2,LENGTH);
    fractal->c.y = map(fractal->y,-2,2,WIDTH);
    while (pow(fractal->z.x,2) + pow(fractal->z.y,2) <= 4 
            && fractal->iter < MAX_ITER) 
    {
        fractal->x_tmp = pow(fractal->z.x,2) - pow(fractal->z.y,2);
        fractal->z.y = 2 * fractal->z.x * fractal->z.y + fractal->c.y;
        fractal->z.x = fractal->x_tmp + fractal->c.x;
        (fractal->iter)++;
    }
    if (pow(fractal->z.x,2) + pow(fractal->z.y,2) > 4)
    {
        fractal->color = map(fractal->iter,BLACK,WHITE,MAX_ITER);
        mlx_pixel_put(fractal->mlx, fractal->win, fractal->x, fractal->y, 
                    fractal->color);
    }
    else
        mlx_pixel_put(fractal->mlx, fractal->win, fractal->x, fractal->y, WHITE);
}

void render_fractal(t_fractal *fractal)
{
    fractal->y = 0;
     while (fractal->y < WIDTH)
        {
            fractal->x = 0;
            while (fractal->x < LENGTH)
            {
                check_pixel(fractal);
                (fractal->x)++;
            }
            (fractal->y)++;
        }
}

int main()  // usage : ./fractol name x y 
{
    t_fractal fractal;

    fractal.mlx = mlx_init();
    if (!fractal.mlx)
        return (MLX_FAIL);
    fractal.win = mlx_new_window(fractal.mlx, LENGTH, WIDTH, "Julia Set");
    if (!fractal.win)
        return NEW_WIN_FAIL;
    render_fractal(&fractal);
    mlx_loop(fractal.mlx);
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