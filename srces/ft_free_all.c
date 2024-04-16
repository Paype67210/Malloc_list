/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:56 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/15 10:07:53 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

int ft_freeall(t_list **list)
{
    t_list *current;
    t_list *next_node;
    
    if (!list || !*list)
        return 1;
    current = *list;
    while (current)
    {
        next_node = current->next;
        free(current->content);
        free(current);
        current = next_node;
    }
    *list = NULL;
    return 0;
}
