/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:50:37 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/18 21:25:52 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenth(int n)
{
	int	res;

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

static char	*alloc(int res)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * res + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, res + 1);
	return (str);
}

static void	fill(char *str, int num, int n)
{
	int		j;
	long	x;

	x = n;
	j = 0;
	num -= 1;
	if (x < 0)
	{
		str[0] = '-';
		x = -x;
		j++;
	}
	while (num >= j)
	{
		str[num] = x % 10 + '0';
		x /= 10;
		num--;
	}
}

char	*ft_itoa(int n)
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
