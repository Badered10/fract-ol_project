/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/23 17:59:15 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_scanstring(char *ptr, char *save_m, t_f *t, va_list args)
{
	while (*ptr)
	{
		if (*ptr == '%')
		{
			save_m = ptr;
			ptr++;
			while (*ptr)
			{
				if (ft_strchr("cspdiuxX%", *ptr))
				{
					t->count += ft_isflag(*(ft_strchr("cspdiuxX%", *ptr)),
							save_m, args);
					break ;
				}
				else if (!*ptr)
					break ;
				ptr++;
			}
		}
		else
			t->count += write(1, ptr, 1);
		if (!*ptr)
			break ;
		ptr++;
	}
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	t_f		t;
	char	*ptr;
	char	*save_m;

	save_m = NULL;
	ptr = (char *)string;
	t.count = 0;
	va_start(args, string);
	ft_scanstring(ptr, save_m, &t, args);
	va_end(args);
	return (t.count);
}
