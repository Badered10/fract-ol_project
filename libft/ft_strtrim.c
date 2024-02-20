/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:29:16 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/22 16:15:18 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_same(char s, char c)
{
	return ((s == c));
}

static size_t	first_wall(const char *s1, const char *set)
{
	int		wall;
	char	*chars;
	char	*string;

	wall = 0;
	string = (char *)s1;
	chars = (char *)set;
	while (*string)
	{
		while (ft_same(*string, *chars) == 1 && *string)
		{
			string++;
			wall++;
		}
		chars = (char *)set;
		while (ft_same(*string, *chars) != 1 && *chars)
			chars++;
		if (!*chars)
			break ;
	}
	return (wall);
}

static size_t	last_wall(const char *s1, const char *set, size_t lenth)
{
	char	*string;
	char	*chars;
	int		wall;

	wall = 0;
	if (lenth != 0)
		lenth = lenth - 1;
	string = (char *)s1 + lenth;
	chars = (char *)set;
	while (lenth)
	{
		while (ft_same(*string, *chars) == 1 && lenth)
		{
			lenth--;
			string--;
			wall++;
		}
		chars = (char *)set;
		while (ft_same(*string, *chars) != 1 && *chars)
			chars++;
		if (!*chars)
			break ;
	}
	return (wall);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	first;
	size_t	last;
	size_t	lenth;
	size_t	total;

	if (!s1 || !set)
		return (NULL);
	lenth = ft_strlen(s1);
	first = first_wall(s1, set);
	last = last_wall(s1, set, lenth);
	if (first == lenth || (!*s1 && !*set))
		total = 1;
	else
		total = (lenth - (first + last)) + 1;
	trim = (char *)malloc(sizeof(char) * total);
	if (!trim)
		return (NULL);
	ft_bzero(trim, total);
	if (total != 1)
		ft_memmove(trim, s1 + first, total - 1);
	return (trim);
}
