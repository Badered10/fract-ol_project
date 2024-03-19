/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parss_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:38:32 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/19 21:30:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static int	julia_seter(char **argv, t_fractal *fractal, int argc)
{
	if (argc != 4)
		syntax_err(fractal);
	fractal->c.x = valid_f(argv[2]);
	fractal->c.y = valid_f(argv[3]);
	if (fabs(fractal->c.x) > 2 || fabs(fractal->c.y) > 2)
		syntax_err(fractal);
	fractal->name = "Julia Set";
	fractal->by_me = "Julia Set By baouragh";
	return (20);
}

static int	check_sets(char **argv, t_fractal *fractal, int argc)
{
	if (argv[1][0] == 'm' || argv[1][0] == 'M')
	{
		if (argc != 2)
			syntax_err(fractal);
		fractal->name = "Mandelbrot Set";
		fractal->by_me = "Mandelbrot Set By baouragh";
		return (10);
	}
	else if (argv[1][0] == 'j' || argv[1][0] == 'J')
		return (julia_seter(argv, fractal, argc));
	else if (argv[1][0] == 't' || argv[1][0] == 'T')
	{
		if (argc != 2)
			syntax_err(fractal);
		fractal->name = "Tricorn Set";
		fractal->by_me = "Tricorn Set By baouragh";
		return (30);
	}
	return (0);
}

void	syntax_err(t_fractal *fractal)
{
	ft_printf("\t[Help Menu]\nSyntax must be : ./fractol first_letter");
	ft_printf("_name\nIn julia case you must enter x and y after 'J'\t");
	ft_printf("example: ./fractol J 0 0.75\n");
	ft_printf("Supported fracts:\nM --> Mendlebort Set\nJ --> Julia Set\n");
	ft_printf("T --> Tricron Set\nB --> Burning ship Set\n");
	clean_close(fractal, 0);
}

int	check_arg_set(char **argv, int argc, t_fractal *fractal)
{
	int	check;

	if (argc < 2 || ft_strlen(argv[1]) != 1)
		syntax_err(fractal);
	check = check_sets(argv, fractal, argc);
	if (check)
		return (check);
	if (argv[1][0] == 'b' || argv[1][0] == 'B')
	{
		if (argc != 2)
			syntax_err(fractal);
		fractal->name = "Burning Ship Set";
		fractal->by_me = "Burning Ship Set By baouragh";
		return (40);
	}
	syntax_err(fractal);
	return (0);
}
