/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:34:35 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/20 22:31:40 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	pixel_image_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	check_pixel(t_fractal *f, t_img *img)
{
	which_fractal(f);
	while ((f->z.x * f->z.x) + (f->z.y * f->z.y) <= 4
		&& f->iter < f->max_iter)
	{
		f->x_tmp = (f->z.x * f->z.x) - (f->z.y * f->z.y);
		if (f->check_set == 40)
			f->z.y = (-2 * fabs(f->z.x) * fabs(f->z.y)) + f->c.y;
		else
			f->z.y = (2 * f->z.x * f->z.y) + f->c.y;
		if (f->check_set == 30)
			f->z.y *= -1;
		f->z.x = f->x_tmp + f->c.x;
		(f->iter)++;
	}
	if (f->iter < f->max_iter)
	{
		f->color = map(f->iter, BLACK, WHITE, f->max_iter);
		pixel_image_put(img, f->x, f->y, f->color);
	}
	else
		pixel_image_put(img, f->x, f->y, f->set_color);
	f->iter = -1;
}
