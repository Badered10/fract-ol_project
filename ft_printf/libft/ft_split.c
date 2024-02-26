/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:18:29 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/22 16:15:11 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **res, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int	ft_wcounter(const char *s, char c)
{
	char	*x;
	int		words;

	words = 0;
	x = (char *)s;
	while (*x)
	{
		while (*x == c && *x)
			x++;
		if (*x)
		{
			while (*x != c && *x)
				x++;
			words++;
		}
	}
	return (words);
}

static void	fill(char ***res, char const *s, char c, int words)
{
	char	*p;
	char	*start;
	int		count;

	count = 0;
	p = (char *)s;
	while (words--)
	{
		while (*p == c)
			p++;
		start = p;
		while (*p != c && *p)
			p++;
		*(*res) = ft_substr(start, 0, p - start);
		if (!*(*res))
		{
			(*res) -= count;
			(*res) = ft_free(*res, count);
			return ;
		}
		count++;
		(*res)++;
	}
	*(*res) = NULL;
	(*res) -= count;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = ft_wcounter(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	fill(&res, s, c, words);
	return (res);
}
