/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/11 17:20:52 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	which_fractal(t_fractal *fractal, char **argv)
{
	if (fractal->check_set == 20)
	{
		fractal->z.x = map(fractal->x, -2, 2, WIDTH) * fractal->new_zoom
			+ fractal->x_shift_value;
		fractal->z.y = map(fractal->y, 2, -2, LENGTH) * fractal->new_zoom
			+ fractal->y_shift_value;
		if (fabs(valid_f(argv[2])) + fabs(valid_f(argv[3])) > 4
			|| valid_f(argv[2]) == 3 || valid_f(argv[3]) == 3)
		{
			ft_printf("Julia Syntax error !\n Range is (-2,2) !\n");
			clean_close(fractal, SYNTAX_ERR);
		}
		fractal->c.x = valid_f(argv[2]);
		fractal->c.y = valid_f(argv[3]);
	}
	else
	{
		fractal->c.x = map(fractal->x, -2, 2, WIDTH) * fractal->new_zoom
			+ fractal->x_shift_value;
		fractal->c.y = map(fractal->y, 2, -2, LENGTH) * fractal->new_zoom
			+ fractal->y_shift_value;
		fractal->z.x = 0;
		fractal->z.y = 0;
	}
}
