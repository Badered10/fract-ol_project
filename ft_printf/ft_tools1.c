/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:13:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/19 11:16:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d_initialize(t_f *nes, int x)
{
	char	*str;

	nes->d = x;
	nes->plus = 0;
	nes->space = 0;
	nes->mince = 0;
	nes->zero = 0;
	nes->point = 0;
	nes->zeros = 0;
	nes->count = 0;
	nes->tmp = -999999999;
	nes->stmp = -999999999;
	str = ft_itoa(nes->d);
	nes->len = ft_strlen(str);
	free(str);
}

void	ft_d_search(t_f *nes, char **string)
{
	while (ft_isdigit_nz(*(*string)) != 1 && *(*string) != '.'
		&& *(*string) != 'd' && *(*string) != 'i' && *(*(string)))
	{
		if (*(*string) == '+')
		{
			nes->plus = 1;
			nes->space = 0;
		}
		else if (*(*string) == ' ')
		{
			if (nes->plus == 0)
				nes->space = 1;
		}
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

void	ft_checkspaces(char **string, t_f *nes)
{
	if (ft_isdigit(*(*string)))
	{
		nes->spaces = ft_atoi(*string);
		nes->stmp = nes->spaces;
		if (nes->spaces > nes->len)
			nes->spaces -= nes->len;
		else
			nes->spaces = 0;
	}
	else
		nes->spaces = 0;
	while (ft_isdigit(*(*string)))
		(*string)++;
}

void	ft_checkpoint(char *string, t_f *nes, unsigned int x)
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

void	ft_dcheckpoint(char **string, t_f *nes, int x)
{
	if (*(*string) == '.')
	{
		nes->point = 1;
		if (*(*string))
			(*string)++;
		if (ft_isdigit(*(*string)))
		{
			nes->zeros = ft_atoi(*string);
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
