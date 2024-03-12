/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:34:35 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/12 18:17:31 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	pixel_image_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	check_pixel(t_fractal *fractal, t_img *img, char **argv)
{
	which_fractal(fractal, argv);
	while (pow(fractal->z.x, 2) + pow(fractal->z.y, 2) <= 4
		&& fractal->iter < fractal->max_iter)
	{
		fractal->x_tmp = pow(fractal->z.x, 2) - pow(fractal->z.y, 2);
		if (fractal->check_set == 30)
			fractal->z.y *= -1;
		if (fractal->check_set == 40)
			fractal->z.y = -2 * fabs(fractal->z.x) * fabs(fractal->z.y)
				+ fractal->c.y;
		else
			fractal->z.y = 2 * fractal->z.x * (fractal->z.y) + fractal->c.y;
		fractal->z.x = fractal->x_tmp + fractal->c.x;
		(fractal->iter)++;
	}
	if (fractal->iter < fractal->max_iter)
	{
		fractal->color = map(fractal->iter, BLACK, WHITE, fractal->max_iter);
		pixel_image_put(img, fractal->x, fractal->y, fractal->color);
	}
	else
		pixel_image_put(img, fractal->x, fractal->y, fractal->set_color);
	fractal->iter = -1;
}
