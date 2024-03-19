/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:34 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/19 23:01:56 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	render_fractal(t_fractal *f)
{
	char	*iter;
	char	*merged;

	iter = ft_itoa(f->max_iter);
	merged = ft_strjoin("iterations: ", iter);
	f->y = 0;
	while (f->y <= LENGTH)
	{
		f->x = 0;
		while (f->x <= WIDTH)
		{
			check_pixel(f, &f->img);
			(f->x)++;
		}
		(f->y)++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	mlx_string_put(f->mlx, f->win, 0, 0, DARK_ORCHID, f->by_me);
	mlx_string_put(f->mlx, f->win, 0, LENGTH / 20, YELLOW, merged);
	free(iter);
	free(merged);
}
