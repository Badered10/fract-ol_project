/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:27:32 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/18 21:47:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(t_f *nes, char *res)
{
	if (nes->mince == 1)
	{
		nes->count += ft_putnstr_fd(res, 1, nes->display);
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
	}
	else
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		nes->count += ft_putnstr_fd(res, 1, nes->display);
	}
}

static void	check_s_spaces(char *string, t_f *nes, char *res)
{
	while (ft_isdigit(*string))
		string++;
	if (*string == '.')
	{
		nes->point = 1;
		string++;
		if (ft_isdigit(*string))
		{
			nes->display = ft_atoi(string);
			if (nes->display > nes->len)
				nes->display = nes->len;
			if ((nes->spaces > nes->display) && res)
				nes->spaces -= nes->display;
			else if (!res)
				nes->spaces -= nes->display;
			else
				nes->spaces = 0;
		}
	}
	else if (nes->point != 1)
	{
		nes->display = nes->len;
		nes->spaces -= nes->display;
	}
}

int	ft_sflags(char *string, char *res)
{
	t_f	nes;

	nes.point = 0;
	nes.mince = 0;
	nes.count = 0;
	while (*string == '-' && *(string + 1))
	{
		nes.mince = 1;
		string++;
	}
	if (res)
		nes.len = ft_strlen(res);
	else
		nes.len = 6;
	if (ft_isdigit(*string))
		nes.spaces = ft_atoi(string);
	else
		nes.spaces = 0;
	check_s_spaces(string, &nes, res);
	ft_print(&nes, res);
	return (nes.count);
}
