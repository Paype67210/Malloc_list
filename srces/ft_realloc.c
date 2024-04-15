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

int ft_realloc(t_list **list, void *ptr, size_t size)
{
    t_list *current;

    if (!list || !*list || !ptr)
        return 0;
    current = *list;
    while (current)
    {
        if (current->content == ptr)
        {
            current->content = realloc(current->content, size);
            if (!current->content)
                return 0;
            current->size = size;
            return 1;
        }
        current = current->next;
    }
    return 0;
}