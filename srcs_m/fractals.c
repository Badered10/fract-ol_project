/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/19 20:36:03 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	which_fractal(t_fractal *fractal)
{
	if (fractal->check_set == 20)
	{
		fractal->z.x = map(fractal->x, -2, 2, WIDTH) * fractal->new_zoom;
		fractal->z.y = map(fractal->y, 2, -2, LENGTH) * fractal->new_zoom;
	}
	else
	{
		fractal->c.x = map(fractal->x, -2, 2, WIDTH) * fractal->new_zoom;
		fractal->c.y = map(fractal->y, 2, -2, LENGTH) * fractal->new_zoom;
		fractal->z.x = 0;
		fractal->z.y = 0;
	}
}
