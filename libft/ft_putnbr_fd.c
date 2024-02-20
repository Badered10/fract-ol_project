/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:20:30 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/20 10:02:58 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	x;

	x = n;
	if (fd < 0)
		return ;
	if (x < 0)
	{
		ft_putchar_fd('-', fd);
		x = -x;
	}
	if (x > 9)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putchar_fd(x % 10 + 48, fd);
	}
	else if (x >= 0 && x <= 9)
	{
		ft_putchar_fd(x + 48, fd);
	}
}
