/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:56 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/15 10:14:42 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

t_list	*ft_lstnew(void *content, int size)
{
	t_list	*cell;

	cell = (t_list *)malloc(sizeof(*cell));
	if (!cell)
		return (NULL);
	cell->content = content;
	cell->size = size;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	
	if (!lst || !new)
        return ;

    if (!*lst)
        *lst = new;
    else {
        last = *lst;
        while (last->next)
            last = last->next;
        last->next = new;
    }
}

void	ft_bzero(void *mtr, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = mtr;
	i = 0;
	if (n > 0)
	{
		while (i < n)
			p[i++] = '\0';
	}
	return ;
}

char	*ft_strnlcpy(const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*dst;

	j = size;
	i = 0;
	dst = malloc((ft_strlen(src) - size + 1) * sizeof(char));
	while (j != ft_strlen(src))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
