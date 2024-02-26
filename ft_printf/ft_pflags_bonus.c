/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:40 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/26 21:17:59 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_print(t_f *nes, char c)
{
	if (nes->mince == 0)
	{
		while (((nes->spaces)-- > 0))
			nes->count += write(1, " ", 1);
		nes->count += ft_putptr_fd(nes->num, 1, c);
	}
	else
	{
		nes->count += ft_putptr_fd(nes->num, 1, c);
		while (((nes->spaces)-- > 0))
			nes->count += write(1, " ", 1);
	}
}

static unsigned long	hexalenth(unsigned long n)
{
	int	res;

	res = 0;
	while (n != 0)
	{
		n /= 16;
		res++;
	}
	return (res);
}

int	ft_pflags(char *string, void *res, char c)
{
	t_f	nes;

	nes.mince = 0;
	nes.count = 0;
	nes.len = 2;
	while (*string == '-' && *(string + 1))
	{
		nes.mince = 1;
		string++;
	}
	nes.num = (unsigned long)res;
	if (nes.num == 0)
		nes.len = 3;
	else
		nes.len += hexalenth(nes.num);
	ft_checkspaces(&string, &nes);
	ft_print(&nes, c);
	return (nes.count);
}
