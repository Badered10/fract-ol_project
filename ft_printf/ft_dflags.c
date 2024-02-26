/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:25 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/26 21:17:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ze_print(t_f *nes)
{
	if (nes->zero == 1)
	{
		if (nes->d < 0)
			write(1, "-", 1);
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_putnbr_fd(nes->d, 1);
	}
	else
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		if (nes->plus == 1 && nes->d >= 0)
			nes->count += write(1, "+", 1);
		if (nes->d < 0)
			write(1, "-", 1);
		nes->count += ft_putnbr_fd(nes->d, 1);
	}
}

static void	d_p_print(t_f *nes, int x)
{
	if (nes->point == 1)
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		if (nes->plus == 1 && nes->d >= 0)
			nes->count += write(1, "+", 1);
		if (nes->d < 0)
			write(1, "-", 1);
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		if (x)
			nes->count += ft_putnbr_fd(nes->d, 1);
		else if (nes->tmp > 0)
			nes->count += ft_putnbr_fd(nes->d, 1);
	}
}

static void	d_m_print(t_f *nes, int x)
{
	if (nes->mince == 1)
	{
		if (nes->d < 0)
			write(1, "-", 1);
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		if (nes->point == 1)
		{
			if (!x && nes->tmp <= 0)
				;
			else
				nes->count += ft_putnbr_fd(nes->d, 1);
		}
		else
			nes->count += ft_putnbr_fd(nes->d, 1);
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
	}
}

static void	ft_checkplus_space(t_f *nes)
{
	if (nes->space == 1 && nes->d >= 0)
	{
		nes->count = write(1, " ", 1);
		if ((nes->zero == 1 && nes->tmp <= nes->len) || nes->tmp < 0)
			nes->zeros--;
		if (nes->tmp >= 0 || nes->point == 0)
			nes->spaces--;
	}
	else if (nes->plus == 1 && nes->d >= 0)
	{
		if (nes->mince == 1 || (nes->zero && !nes->point))
			nes->count = write(1, "+", 1);
		if ((nes->zero == 1 && nes->tmp <= nes->len) || nes->tmp < 0)
			nes->zeros--;
		if (nes->tmp >= 0 || nes->point == 0)
			nes->spaces--;
	}
}

int	ft_dflags(char *string, int x)
{
	t_f	nes;

	ft_d_initialize(&nes, x);
	ft_d_search(&nes, &string);
	ft_checkspaces(&string, &nes);
	ft_dcheckpoint(&string, &nes, x);
	ft_checkplus_space(&nes);
	if (nes.mince == 1)
		d_m_print(&nes, x);
	else if (nes.point == 1)
		d_p_print(&nes, x);
	else
		ze_print(&nes);
	return (nes.count);
}
