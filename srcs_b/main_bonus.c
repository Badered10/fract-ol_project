/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/12 18:17:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Julia , Mandelbrot
#include "../headers/fractol.h"

int	main(int argc, char **argv) // usage : ./fractol name x y
{
	t_fractal	fractal;

	fractal_init(&fractal, argv, argc);
	fractal.check_set = check_arg_set(argv, argc, &fractal);
	fractal.mlx = mlx_init();
	if (!fractal.mlx)
		exit(MLX_FAIL);
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, LENGTH, fractal.name);
	if (!fractal.win)
		clean_close(&fractal, NEW_WIN_FAIL);
	render_fractal(&fractal, argv);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_hook(fractal.win, 17, 0, destroy_notify, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
