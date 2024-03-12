/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:34 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/12 18:16:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	render_fractal(t_fractal *f, char **argv)
{
	char	*iter;
	char	*merged;

	iter = ft_itoa(f->max_iter);
	merged = ft_strjoin("iterations: ", iter);
	mlx_clear_window(f->mlx, f->win);
	f->img.img = mlx_new_image(f->mlx, WIDTH + 1, LENGTH + 1);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	f->y = 0;
	while (f->y <= LENGTH)
	{
		f->x = 0;
		while (f->x <= WIDTH)
		{
			check_pixel(f, &f->img, argv);
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
