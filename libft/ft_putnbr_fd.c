/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:20:30 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/23 01:34:26 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	x;
	int		count;

	count = 0;
	x = n;
	if (fd < 0)
		return (-1);
	if (x < 0)
	{
		count += 1;
		x = -x;
	}
	if (x > 9)
	{
		count += ft_putnbr_fd(x / 10, fd);
		count += ft_putchar_fd(x % 10 + 48, fd);
	}
	else if (x >= 0 && x <= 9)
	{
		count += ft_putchar_fd(x + 48, fd);
	}
	return (count);
}
