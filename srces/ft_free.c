/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:56 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/15 09:01:39 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

int    ft_free(t_list **list, void *ptr)
{
    t_list *current;
    t_list *prev;

    if (!list || !*list || !ptr)
        return 1;
    current = *list;
    prev = NULL;
    while (current)
    {
        if (current->content == ptr)
        {
            if (prev)
                prev->next = current->next;
            else
                *list = current->next;
            free(current->content);
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 1;
}
