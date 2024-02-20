/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:53:19 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/24 16:49:43 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*var;
	int		res;
	int		signe;

	var = (char *)str;
	res = 0;
	signe = 1;
	while ((*var >= 9 && *var <= 13) || *var == 32)
		var++;
	if (*var == '-' || *var == '+')
	{
		if (*var == '-')
			signe *= -1;
		var++;
	}
	while (*var && *var >= '0' && *var <= '9')
	{
		res = res * 10 + (*var - '0');
		var++;
	}
	res *= signe;
	return (res);
}
