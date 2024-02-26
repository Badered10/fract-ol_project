/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:45 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/26 21:27:01 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_flags
{
	unsigned long	num;
	int				d;
	unsigned int	ud;
	int				count;
	int				spaces;
	int				zeros;
	int				display;
	int				len;
	int				tmp;
	int				stmp;
	int				plus;
	int				space;
	int				mince;
	int				zero;
	int				point;
	int				hashtag;
}	t_f;

int					ft_printf(const char *string, ...);
int					ft_dflags(char *string, int x);
int					ft_isflag(char ch, char *save_m, va_list args);
int					ft_cflags(char *save_m, int x);
int					ft_uflags(char *string, unsigned int x);
int					ft_sflags(char *string, char *res);
int					ft_pflags(char *string, void *res, char c);
int					ft_xsflags(char *string, unsigned int x, char c);
void				ft_d_initialize(t_f *nes, int x);
void				ft_d_search(t_f *nes, char **string);
void				ft_checkspaces(char **string, t_f *nes);
void				ft_checkpoint(char *string, t_f *nes, unsigned int x);
void				ft_dcheckpoint(char **string, t_f *nes, int x);
void				p_x_print(t_f *nes, unsigned int x, char c);
void				ft_x_search(char **string, t_f *nes);
void				check_hashtag(t_f *nes, unsigned int x, char c);
void				ft_check_u_point(char *string, t_f *nes, unsigned int x);

#endif