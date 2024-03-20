/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:36:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/20 22:59:43 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static void	hundlle_keys(int *keycode, t_fractal *fractal)
{
	if (*keycode == 53)
		clean_close(fractal, 0);
	else if (*keycode == 12 && fractal->set_color != DARK_ORCHID)
		fractal->set_color = DARK_ORCHID;
	else if (*keycode == 13 && fractal->set_color != GOLDENROD)
		fractal->set_color = GOLDENROD;
	else if (*keycode == 2 && fractal->set_color != BLACK)
		fractal->set_color = BLACK;
	else if (*keycode == 1 && fractal->set_color != WHITE)
		fractal->set_color = WHITE;
	else
		*keycode = 0;
}

int	key_hook(int keycode, t_fractal *fractal)
{
	hundlle_keys(&keycode, fractal);
	if ((keycode >= 12 && keycode <= 13) || keycode == 2 || keycode == 1)
		render_fractal(fractal);
	return (0);
}

int	destroy_notify(t_fractal *fractal)
{
	clean_close(fractal, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;

	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		if (button == 5)
			zoom_factor = 0.9;
		else
			zoom_factor = 1.1;
		fractal->zoom_level *= zoom_factor;
		render_fractal(fractal);
	}
	if (button == 1)
	{
		mlx_clear_window(fractal->mlx, fractal->win);
		render_fractal(fractal);
	}
	return (0);
}
