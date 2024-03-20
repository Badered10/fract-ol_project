/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/20 22:59:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	main(int argc, char **argv)
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
	fractal.img.img = mlx_new_image(fractal.mlx, WIDTH + 1, LENGTH + 1);
	fractal.img.addr = mlx_get_data_addr(fractal.img.img, &fractal.img.bpp,
			&fractal.img.line_len, &fractal.img.endian);
	render_fractal(&fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_hook(fractal.win, 17, 0, destroy_notify, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
