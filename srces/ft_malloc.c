/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:56 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/17 08:39:54 by pdeson           ###   ########.fr       */
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
	ft_bzero(buffer, size);
	new_node->content = buffer;
	new_node->size = size;
	new_node->next = NULL;
	ft_lstadd_back(ouille, new_node);
	return (buffer);
}

void	*ft_run_malloc(int function, ...)
{
	static t_list	*g_ouille;
	va_list			args;
	void			*ptr;

	va_start(args, function);
	if (!g_ouille)
		g_ouille = NULL;
	if (function == 1)	// malloc
		return (ft_malloc(&g_ouille, va_arg(args, size_t)));
	else if (function == 2)	// free
	{
		ptr = va_arg(args, void *);
		if (ft_free(&g_ouille, ptr) == 1)
			return (ptr);
		return (NULL);
	}
	else if (function == 3)	// realloc
		return (ft_realloc(&g_ouille, va_arg(args, void *), \
			va_arg(args, size_t)));
	else if (function == 4)	// freeall
	{
		ft_freeall(&g_ouille);
		return (g_ouille);
	}
	return (va_end(args), NULL);
}
