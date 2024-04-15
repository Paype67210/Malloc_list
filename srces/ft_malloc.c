/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:56 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/15 09:35:53 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

void	*ft_malloc(t_list **ouille, size_t size)
{
	void	*buffer;
	t_list	*new_node;

	buffer = malloc(size);
	if (!buffer)
		return (NULL);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		return (NULL);
	}
	new_node->content = buffer;
	new_node->size = size;
	new_node->next = NULL;
	ft_lstadd_back(ouille, new_node);
	return (buffer);
}
