/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:17:32 by philippe          #+#    #+#             */
/*   Updated: 2024/04/15 10:18:10 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

int *ft_realloc(t_list **list, void *ptr, size_t size)
{
    t_list *current;
    void    *buffer;

    if (!list || !*list || !ptr)
        return 0;
    buffer = malloc(size);
    if (!buffer)
        return (NULL);
    ft_bzero(buffer, size);
    buffer = ft_strnlcpy(ptr, size - 1);
    free(ptr);
    current = *list;
    while (current)
    {
        if (current->content == ptr)
        {
            current->content = buffer;
            if (!current->content)
                return (NULL);
            current->size = size;
            return (current->content);
        }
        current = current->next;
    }
    return (free(buffer), NULL);
}
