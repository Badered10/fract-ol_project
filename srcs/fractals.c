/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/07 12:13:10 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void which_fractal(t_fractal *fractal, char **argv)
{
    if (fractal->check_set == 10)
    {
        fractal->c.x = map(fractal->x, -2, 2, LENGTH) * fractal->zoom_value  +
                        fractal->x_shift_value;
        fractal->c.y = map(fractal->y, 2, -2, WIDTH) * fractal->zoom_value  +
                        fractal->y_shift_value;
        fractal->z.x = 0;
        fractal->z.y = 0;
    }
    else if (fractal->check_set == 20)
    {
            fractal->z.x = map(fractal->x,-2,2,LENGTH) * fractal->zoom_value + 
                        fractal->x_shift_value;
            fractal->z.y = map(fractal->y,2,-2,WIDTH) * fractal->zoom_value + 
                        fractal->y_shift_value;
            if (fabs(check_valid_float(argv[2])) + fabs(check_valid_float(argv[3])) > 4)
            {
                ft_printf("Julia range is (-2,2) !\n");
                clean_close(fractal,SYNTAX_ERR);
            }
            fractal->c.x = check_valid_float(argv[2]);
            fractal->c.y = check_valid_float(argv[3]);
    }
    fractal->iter = 0;
}
