/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:57:29 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/18 21:47:30 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_assister(char *string, t_f *nes)
{
	if (ft_isdigit(*string))
	{
		nes->spaces = ft_atoi(string);
		if (nes->spaces > nes->len)
			nes->spaces = nes->spaces - nes->len;
		else
			nes->spaces = 0;
	}
	else
		nes->spaces = 0;
	while (ft_isdigit(*string))
		string++;
	if (nes->mince == 0)
	{
		while (((nes->spaces)-- > 0))
			nes->count += write(1, " ", 1);
		nes->count += ft_putchar_fd(nes->d, 1);
	}
	else
	{
		nes->count += ft_putchar_fd(nes->d, 1);
		while (((nes->spaces)-- > 0))
			nes->count += write(1, " ", 1);
	}
}

int	ft_cflags(char *string, int x)
{
	t_f	nes;

	nes.mince = 0;
	nes.count = 0;
	while (*string == '-' && *(string + 1))
	{
		nes.mince = 1;
		string++;
	}
	nes.d = x;
	nes.len = 1;
	return (ft_assister(string, &nes), nes.count);
}
