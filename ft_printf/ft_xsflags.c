/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:51 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/23 17:59:15 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ze_print(t_f *nes, unsigned int x, char c)
{
	if (nes->zero == 1)
	{
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_puthexa_fd(x, 1, c);
	}
	else
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		if (nes->hashtag == 1 && x && c == 'x')
			nes->count += write(1, "0x", 2);
		else if (nes->hashtag == 1 && x && c != 'x')
			nes->count += write(1, "0X", 2);
		nes->count += ft_puthexa_fd(x, 1, c);
	}
}

static void	m_x_print(t_f *nes, unsigned int x, char c)
{
	if (nes->mince == 1)
	{
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_puthexa_fd(x, 1, c);
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
	}
}

static void	check_x_point(char *string, t_f *nes)
{
	if (*string == '.' && *(string + 1))
	{
		nes->point = 1;
		string++;
		if (ft_isdigit(*string))
		{
			nes->zeros = ft_atoi(string);
			nes->tmp = nes->zeros;
			if (nes->zeros > nes->len)
				nes->zeros -= nes->len;
			else
				nes->zeros = 0;
		}
	}
	else if (nes->zero == 1)
		nes->zeros = nes->spaces;
	nes->spaces -= nes->zeros;
}

static int	hexalenth(unsigned long n)
{
	int	res;

	res = 1;
	if (n > 0)
		res = 0;
	while (n != 0)
	{
		n /= 16;
		res++;
	}
	return (res);
}

int	ft_xsflags(char *string, unsigned int x, char c)
{
	t_f	nes;

	nes.mince = 0;
	nes.zero = 0;
	nes.hashtag = 0;
	nes.point = 0;
	nes.zeros = 0;
	nes.count = 0;
	nes.len = 0;
	nes.tmp = -999999999;
	nes.len += hexalenth(x);
	ft_x_search(&string, &nes);
	ft_checkspaces(&string, &nes);
	check_x_point(string, &nes);
	check_hashtag(&nes, x, c);
	if (nes.mince == 1)
		m_x_print(&nes, x, c);
	else if (nes.point == 1)
		p_x_print(&nes, x, c);
	else
		ze_print(&nes, x, c);
	return (nes.count);
}
