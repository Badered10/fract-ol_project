/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:34 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/06 15:40:45 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void render_fractal(t_fractal *fractal, char **argv)
{
    mlx_clear_window(fractal->mlx, fractal->win);
    fractal->img.img = mlx_new_image(fractal->mlx,WIDTH + 1,LENGTH + 1);
    fractal->img.addr = mlx_get_data_addr(fractal->img.img,&fractal->img.bpp,&fractal->img.line_length,&fractal->img.endian);
    fractal->y = 0;
     while (fractal->y <= WIDTH)
        {
            fractal->x = 0;
            while (fractal->x <= LENGTH)
            {
                check_pixel(fractal, &fractal->img, argv);
                (fractal->x)++;
            }
            (fractal->y)++;
        }
    mlx_put_image_to_window(fractal->mlx,fractal->win,fractal->img.img,0,0);
    mlx_string_put(fractal->mlx, fractal->win, 0, 0,BLACK,fractal->by_me);
}
