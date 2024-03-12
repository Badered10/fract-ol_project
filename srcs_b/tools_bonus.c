/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:33:11 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/12 18:17:40 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	clean_close(t_fractal *fractal, int id)
{
	if (fractal->mlx)
	{
		if (fractal->win)
		{
			if (fractal->img.img)
				mlx_destroy_image(fractal->mlx, fractal->img.img);
			mlx_clear_window(fractal->mlx, fractal->win);
			mlx_destroy_window(fractal->mlx, fractal->win);
		}
		system("leaks fractol");
		exit(id);
	}
	else
		exit(id);
}

void	fractal_init(t_fractal *fractal, char **argv, int argc)
{
	ft_bzero(fractal, sizeof(t_fractal));
	fractal->argc = argc;
	fractal->argv = argv;
	fractal->max_iter = 20;
	fractal->new_zoom = 1;
	fractal->iter = -1;
}

double	map(double unsacled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unsacled_num / old_max + new_min);
}
