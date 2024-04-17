/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:17:32 by philippe          #+#    #+#             */
/*   Updated: 2024/04/17 09:28:34 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

int	*ft_realloc(t_list **list, void *ptr, size_t size)
{
	t_list	*current;
	void	*buffer;

	if (!list || !*list || !ptr)
		return (NULL);
	current = *list;
	while (current)
	{
		if (current->content == ptr)
		{
			buffer = realloc(ptr, size);
			if (!buffer)
				return (NULL);
			if (size > (unsigned long)current->size)
				ft_bzero((char *)buffer + current->size, size - current->size);
			current->content = buffer;
			current->size = size;
			return (current->content);
		}
		current = current->next;
	}
	return (NULL);
}
