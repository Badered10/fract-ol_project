/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:36:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/06 21:50:37 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int key_hook(int keycode, t_fractal *fractal) // x <- 123 , x -> 124 , y down 125 ,y up 126
{
    if (keycode == 53)
        clean_close(fractal,0);
    if (keycode == 123)
        fractal->x_shift_value -= 0.5 * (fractal->zoom_value);
    else if (keycode == 124)
        fractal->x_shift_value += 0.5 * (fractal->zoom_value);
    else if (keycode == 125)
        fractal->y_shift_value -= 0.5 * (fractal->zoom_value);
    else if (keycode == 126)
        fractal->y_shift_value += 0.5 * (fractal->zoom_value);
    else if (keycode == 24)
        fractal->max_iter += 10;
    else if (keycode == 27)
    {
        if (fractal->max_iter > 30)
            fractal->max_iter -= 10;
    }
    if ( (keycode >= 123 && keycode <= 126 ) || keycode == 24 || keycode == 27)
        render_fractal(fractal, fractal->argv);
    return (0);
}

int destroy_notify(t_fractal *fractal)
{
    clean_close(fractal , 0);
    return (0);
}
int     mouse_hook(int button, int x, int y, t_fractal *fractal)
{
        double  zoom_factor;
        double  mouse_x;
        double  mouse_y;

        if (button == 4 || button == 5)
        {
                if (button == 5)
                        zoom_factor = 0.9;
                else
                        zoom_factor = 1.1;
                fractal->zoom_value *= zoom_factor;
                mouse_x = map(x, -2, 2, LENGTH) * fractal->zoom_value + fractal->x_shift_value;
                mouse_y = map(y, 2, -2, WIDTH) * fractal->zoom_value + fractal->y_shift_value;
                fractal->x_shift_value = mouse_x - (mouse_x - fractal->x_shift_value) * zoom_factor;
                fractal->y_shift_value = mouse_y - (mouse_y - fractal->y_shift_value) * zoom_factor;
                render_fractal(fractal, fractal->argv);
        }
        return (0);
}
