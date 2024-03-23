/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:20:43 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/23 01:34:26 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_puthexa_fd(unsigned int res, int fd, char ch)
{
	int		count;
	char	*str;

	count = 0;
	if ((fd < 0))
		return (-1);
	str = ft_itohexa(res, ch);
	if (!str)
		return (0);
	count += write(fd, str, ft_strlen(str));
	free(str);
	return (count);
}
