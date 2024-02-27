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

#endif