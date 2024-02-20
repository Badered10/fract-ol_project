/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/19 16:45:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Julia , Mandelbrot
#include "../headers/fractol.h"

int main (int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int x;

    x = 0;

    void *mlx;
    mlx = mlx_init();
    x = *((int *)mlx);
    printf("mlx --> %d\n",x);
    // mlx_new_window (mlx, 1920, 1080,"new window");
    // mlx_loop(mlx);
}