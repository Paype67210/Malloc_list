/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:43:24 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/27 10:09:26 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

t_list	*ft_lstnew(void *content, int size)
{
	t_list	*cell;

	cell = (t_list *)malloc(sizeof(*cell));
	if (!cell)
		return (NULL);
	cell->content = content;
	cell->size = size;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buffer;

	if (!lst)
		return (NULL);
	buffer = lst;
	while (buffer->next)
			buffer = buffer->next;
	return (buffer);
}

t_list	*ft_lstfirst(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	if (lst->content == NULL)
		lst = lst->next;
	return (lst);
}
