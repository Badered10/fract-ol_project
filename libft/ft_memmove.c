/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:47:22 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/22 10:41:27 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!src && !dst)
		return (NULL);
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (len != 0)
	{
		destination[len - 1] = source[len - 1];
		len--;
	}
	return ((void *)destination);
}
