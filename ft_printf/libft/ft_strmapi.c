/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:12:32 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/21 22:47:55 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			length;
	unsigned int	i;
	char			*b;

	i = 0;
	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	b = malloc(sizeof(char) * (length + 1));
	if (!b)
		return (NULL);
	while (s[i])
	{
		b[i] = f(i, s[i]);
		i++;
	}
	b[i] = '\0';
	return (b);
}
