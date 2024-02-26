/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:31:57 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/18 13:58:25 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(unsigned long res, int fd, char ch)
{
	int		count;
	char	*str;

	count = 0;
	if ((fd < 0))
		return (-1);
	str = ft_itohexa(res, ch);
	if (!str)
		return (0);
	count += write(1, "0x", 2);
	count += write(fd, str, ft_strlen(str));
	free(str);
	return (count);
}
