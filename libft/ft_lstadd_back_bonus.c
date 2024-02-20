/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:55 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/15 16:44:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list	*tmp;

	if (!lst || !new_list)
		return ;
	if (!*lst)
	{
		*lst = new_list;
		return ;
	}
	tmp = (*lst);
	tmp = ft_lstlast(tmp);
	tmp->next = new_list;
}
