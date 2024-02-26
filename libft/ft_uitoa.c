/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:50:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/26 21:33:10 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static unsigned int	lenth(unsigned int n)
{
	unsigned int	res;

	res = 1;
	if (n > 0)
		res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*alloc(unsigned int res)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * res + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, res + 1);
	return (str);
}

static void	fill(char *str, int num, unsigned int n)
{
	unsigned int	x;

	x = n;
	num -= 1;
	while (num >= 0)
	{
		str[num] = x % 10 + '0';
		x /= 10;
		num--;
	}
}

char	*ft_uitoa(unsigned int n)
{
	char	*res;
	int		num;

	num = lenth(n);
	res = alloc(num);
	if (!res)
		return (NULL);
	fill(res, num, n);
	return (res);
}
