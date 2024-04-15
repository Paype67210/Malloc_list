/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/15 10:23:06 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_LIST_H
# define MALLOC_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <limits.h>

/*
	content = pointer vers le malloc
	size = taille du malloc (en octets) avec le + 1 pour le '\0'
	next = pointer vers la node suivante
	prev = pointer vers la node precedente
*/

typedef struct s_list
{
	void			*content;
	int				size;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

/* ---------- LINKED LISTS ------- */
t_list	*ft_lstnew(void *content, int size);
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t	ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *str);
/* ---------- FT_MALLOC ---------- */
void	*ft_malloc(t_list **ouille, size_t size);
void	ft_printlist(t_list *list);
int		ft_realloc(t_list **list, void *ptr, size_t size);
/* ---------- FT_FREE ---------- */
int		ft_free(t_list **list, void *ptr);
int 	ft_freeall(t_list **list);

#endif
