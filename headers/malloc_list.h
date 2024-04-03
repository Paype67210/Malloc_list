/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/27 10:08:07 by pdeson           ###   ########.fr       */
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
	type = 0: int*, 1:char*, 2:char**, 3:char***
	size = taille du malloc - 1
	next = pointer vers la node suivante
*/

typedef struct s_list
{
	void			*content;
	int				type;
	int				size;
	struct s_list	*next;
}	t_list;

/* ---------- LINKED LISTS ------- */
t_list	*ft_lstnew(void *content, int type);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfirst(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int	ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstclear_safe(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int	ft_lstremove(t_list **lst, t_list *node, void (*del)(void*));
t_list	*ft_lstretrieve(t_list **lst, t_list *node);

#endif
