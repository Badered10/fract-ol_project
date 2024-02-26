/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:20:49 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 22:29:16 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	x;
	int				count;

	count = 0;
	x = n;
	if (fd < 0)
		return (-1);
	if (x < 0)
	{
		count += ft_putchar_fd('-', fd);
		x = -x;
	}
	if (x > 9)
	{
		count += ft_putunbr_fd(x / 10, fd);
		count += ft_putchar_fd(x % 10 + 48, fd);
	}
	else if (x >= 0 && x <= 9)
	{
		count += ft_putchar_fd(x + 48, fd);
	}
	return (count);
}
