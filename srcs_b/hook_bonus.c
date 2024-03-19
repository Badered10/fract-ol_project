/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:36:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/19 23:28:50 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

/*
	x left 123 , x right 124 , y down 125 ,y up 126
*/

static void	hundlle_keys(int *keycode, t_fractal *fractal)
{
	if (*keycode == 53)
		clean_close(fractal, 0);
	else if (*keycode == 123)
		fractal->x_shift -= (0.5 * fractal->zoom_level);
	else if (*keycode == 124)
		fractal->x_shift += (0.5 * fractal->zoom_level);
	else if (*keycode == 125)
		fractal->y_shift -= (0.5 * fractal->zoom_level);
	else if (*keycode == 126)
		fractal->y_shift += (0.5 * fractal->zoom_level);
	else if (*keycode == 24)
		fractal->max_iter += 10;
	else if (*keycode == 27)
		fractal->max_iter -= 10;
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
	if (fractal->max_iter == 10)
		fractal->max_iter = 20;
	else if ((keycode >= 123 && keycode <= 126) || keycode == 24
		|| keycode == 27 || (keycode >= 12 && keycode <= 13) || keycode == 2
		|| keycode == 1)
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
	double	mouse_x;
	double	mouse_y;

	if (button == 4 || button == 5)
	{
		if (button == 5)
			zoom_factor = 0.9;
		else
			zoom_factor = 1.1;
		fractal->zoom_level *= zoom_factor;
		mouse_x = map(x, -2, 2, WIDTH) * fractal->zoom_level;
		mouse_y = map(y, 2, -2, LENGTH) * fractal->zoom_level;
		fractal->x_shift = (fractal->x_shift + mouse_x)
			- (mouse_x * zoom_factor);
		fractal->y_shift = (fractal->y_shift + mouse_y)
			- (mouse_y * zoom_factor);
		render_fractal(fractal);
	}
	return (0);
}
