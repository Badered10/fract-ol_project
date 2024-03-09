/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:34 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/09 15:33:58 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void render_fractal(t_fractal *fractal, char **argv)
{
    char *iter;
    char *merged;

    iter = ft_itoa(fractal->max_iter);
    merged = ft_strjoin("iterations: ", iter);
    mlx_clear_window(fractal->mlx, fractal->win);
    fractal->img.img = mlx_new_image(fractal->mlx, WIDTH + 1, LENGTH + 1);
    fractal->img.addr = mlx_get_data_addr(fractal->img.img,&fractal->img.bpp,&fractal->img.line_WIDTH,&fractal->img.endian);
    fractal->y = 0;
     while (fractal->y <= LENGTH)
        {
            fractal->x = 0;
            while (fractal->x <= WIDTH)
            {
                check_pixel(fractal, &fractal->img, argv);
                (fractal->x)++;
            }
            (fractal->y)++;
        }
    mlx_put_image_to_window(fractal->mlx,fractal->win,fractal->img.img,0,0);
    mlx_string_put(fractal->mlx, fractal->win, 0, 0, DARK_ORCHID, fractal->by_me);
    mlx_string_put(fractal->mlx, fractal->win, 0, LENGTH / 20, YELLOW, merged);
    free (iter);
    free (merged);
}
