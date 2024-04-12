/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:56 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/27 09:18:33 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

void	*ft_malloc(t_list *ouille, size_t size)
{
	void	*buffer;

	buffer = malloc(size);
	if (!buffer)
		return (NULL);
	ft_lstadd_back(&ouille, ft_lstnew(buffer, size));
	printf("Taille_list: %i\n", ft_lstsize(ouille));
	return (buffer);
}
