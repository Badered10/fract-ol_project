/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:38:32 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/06 15:40:05 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void syntax_err(int id, char *arg , t_fractal *fractal)
{
    if (!ft_strncmp(arg,"help",ft_strlen(arg)))
    {
        ft_printf("\t[Help Menu]\nSyntax must be : as folow: ./fractol fractal");
        ft_printf("_name\nIn julia fractal you must enter x and y after name\n");
        ft_printf("Supported fracts:\nM --> Mendlebort Set\nJ --> Julia Set\n");
        clean_close(fractal,0);
    }
    else if (!id)
        ft_printf("You enterd unsupported fractal\nFor mor infos enter './farctol help'");
    else if (id == 20 || id == 10 || id == 30)
         ft_printf("Syntax Error \nFor mor infos enter './farctol help'");
    clean_close(fractal,1);
}
int check_arg_set(char **argv, int argc , t_fractal *fractal)
{
      if (argc < 2)
        syntax_err(0, "help", fractal);
    if (ft_strlen(argv[1]) != 1)
        syntax_err(0,argv[1],fractal);
    if (argv[1][0] == 'm' || argv[1][0] == 'M')
    {
        if (argc != 2) // ./fractal M
            syntax_err(10, argv[1], fractal);
        fractal->name = "Mandelbrot Set";
        fractal->by_me = "Mandelbrot Set By baouragh";
        return (10);
    }
    else if (argv[1][0] == 'j' || argv[1][0] == 'J')
    {
        if (argc != 4) // ./fractal J x y
            syntax_err(20, argv[1], fractal);
            fractal->name = "Julia Set";
            fractal->by_me = "Julia Set By baouragh";
        return (20);
    }
    else if (argv[1][0] == 's' || argv[1][0] == 'S') // TO DO Sierpinski Gasket;
        return (30);
    syntax_err(0, "help" ,fractal);
    return (0);
}
 