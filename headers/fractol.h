/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:24:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/09 23:41:42 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

/*
    Number that stands for telling the user that mlx_int() fails.
*/
# define MLX_FAIL 1
# define NEW_WIN_FAIL 2
# define SYNTAX_ERR 3
/*
    y
*/
# define LENGTH 480
/*
    x
*/
# define WIDTH 640
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define SKY_BLUE 0x87CEEB
# define DARK_SLATE_GRAY 0x2F4F4F
# define FOREST_GREEN 0x228B22
# define SLATE_BLUE 0x6A5ACD
# define GOLDENROD 0xDAA520
# define SALMON 0xFA8072
# define TEAL 0x008080
# define LAVENDER 0xE6E6FA
# define CORAL 0xFF7F50
# define INDIGO 0x4B0082
# define TURQUOISE 0x40E0D0
# define DARK_ORCHID 0x9932CC
# define OLIVE 0x808000
# define TOMATO 0xFF6347
# define CHOCOLATE 0xD2691E

typedef struct s_d
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_image_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fractal
{
	t_complex	z;
	t_complex	c;
	void		*mlx;
	void		*win;
	t_img		img;
	char		*name;
	char		*by_me;
	char		**argv;
	int			iter;
	int			color;
	int			set_color;
	double		x;
	double		y;
	int			check_set;
	int			argc;
	int			max_iter;
	double		mouse_x;
	double		mouse_y;
	double		x_tmp;
	double		x_shift_value;
	double		y_shift_value;
	double		new_zoom;
	double		x_zoom;
	double		y_zoom;
}				t_fractal;

void	which_fractal(t_fractal *fractal, char **argv);
int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		destroy_notify(t_fractal *fractal);
void	pixel_image_put(t_img *img, int x, int y, int color);
void	check_pixel(t_fractal *fractal, t_img *img, char **argv);
void	syntax_err(int id, char *arg, t_fractal *fractal);
int		check_arg_set(char **argv, int argc, t_fractal *fractal);
void	render_fractal(t_fractal *fractal, char **argv);
void	clean_close(t_fractal *fractal, int id);
void	fractal_init(t_fractal *fractal, char **argv, int argc);
double	map(double unsacled_num, double new_min, double new_max,
			double old_max);

#endif