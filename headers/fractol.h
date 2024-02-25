/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:24:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/25 15:44:58 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../headers/libft.h"
# include <mlx.h>
# include <math.h>

/*
    Number that stands for telling the user that mlx_int() fails.
*/
# define MLX_FAIL 1
# define NEW_WIN_FAIL 2
# define MAX_ITER 1000
# define WIDTH 500 //y
# define LENGTH 500// x

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define YELLOW 0xFFFF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define ORANGE 0xFFA500
#define PURPLE 0x800080
#define SKY_BLUE 0x87CEEB
#define DARK_SLATE_GRAY 0x2F4F4F
#define FOREST_GREEN 0x228B22
#define SLATE_BLUE 0x6A5ACD
#define GOLDENROD 0xDAA520
#define SALMON 0xFA8072
#define TEAL 0x008080
#define LAVENDER 0xE6E6FA
#define CORAL 0xFF7F50
#define INDIGO 0x4B0082
#define TURQUOISE 0x40E0D0
#define DARK_ORCHID 0x9932CC
#define OLIVE 0x808000
#define TOMATO 0xFF6347
#define CHOCOLATE 0xD2691E

double map(double unsacled_num, double new_min, double new_max , double old_max)
{
    return ((new_max - new_min) * unsacled_num / old_max + new_min);
}

typedef struct s_d
{
    double x;
    double y;
}               t_complex;

typedef struct s_fractal
{
    void *mlx;
    void *win;
    t_complex z;
    t_complex c;
    int iter;
    double x_tmp;
    int color;
    int x;
    int y;
    int width;
    int height;
}               t_fractal;

typedef struct	s_image_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

#endif