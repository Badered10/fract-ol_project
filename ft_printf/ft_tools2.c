/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:30:44 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/23 17:59:15 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	p_x_print(t_f *nes, unsigned int x, char c)
{
	if (nes->point == 1)
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		if (nes->hashtag == 1 && x && c == 'x')
			nes->count += write(1, "0x", 2);
		else if (nes->hashtag == 1 && x && c != 'x')
			nes->count += write(1, "0X", 2);
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_puthexa_fd(x, 1, c);
	}
}

void	ft_x_search(char **string, t_f *nes)
{
	while (ft_isdigit_nz(*(*string)) != 1 && *(*string) != '.'
		&& *(*string) != 'x' && *(*string) != 'X' && *(*(string)))
	{
		if (*(*string) == '#')
			nes->hashtag = 1;
		else if (*(*string) == '0')
		{
			if (nes->mince == 0)
				nes->zero = 1;
		}
		else if (*(*string) == '-')
		{
			nes->zero = 0;
			nes->mince = 1;
		}
		(*string)++;
	}
}

void	check_hashtag(t_f *nes, unsigned int x, char c)
{
	if (nes->hashtag == 1 && x)
	{
		if (((nes->mince == 1 && x) || (nes->zero && !nes->point)) && c == 'x')
			nes->count += write(1, "0x", 2);
		else if (((nes->mince == 1 && x) || (nes->zero && !nes->point))
			&& c != 'x')
			nes->count += write(1, "0X", 2);
		if ((nes->zero == 1 && nes->tmp <= nes->len) || nes->tmp == -999999999)
			nes->zeros -= 2;
		if (nes->tmp != -999999999 || nes->point == 0)
			nes->spaces -= 2;
	}
}

void	ft_check_u_point(char *string, t_f *nes, unsigned int x)
{
	if (*string == '.')
	{
		nes->point = 1;
		if (*string)
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
		if (!x && nes->stmp >= 1 && nes->tmp <= 0)
			nes->spaces++;
	}
	else if (nes->zero == 1)
		nes->zeros = nes->spaces;
	if (((nes->zeros > 0) || (nes->len == nes->tmp)) && (nes->d < 0
			&& nes->point == 1))
		nes->zeros++;
	nes->spaces -= nes->zeros;
}
