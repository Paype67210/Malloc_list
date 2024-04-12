/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:56 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/27 10:14:53 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

void	ft_printlist(t_list *list)
{
	t_list	*buffer;

	buffer = list;
	while (buffer)
	{
		printf("%p\n", buffer->content);
	//if (buffer->next)
	 		buffer = buffer->next;
	}
}

int	main(void)
{
	t_list	*ouille;
	char	*str;
	size_t	i;

	ouille = ft_lstnew(NULL, 0);
	/* impression d'un CHAR * */
	str = (char *)ft_malloc(ouille, 10 * sizeof(char));
	printf("str: %p\n", str);
	for (i = 0; i < 10; i++)
		str[i] = 'a' + i;
	printf("%s\n", str);
	printf("------\n");
	/* impression d'un CHAR ** */
	char	**array;

	array = (char **)ft_malloc(ouille, 4 * sizeof(char *));
	printf("array: %p\n", array);
	int	j;
	for (j = 0; j < 3; j++) {
		array[j] = (char *)ft_malloc(ouille, 11 * sizeof(char));
		for (int k = 0; k < 10; k++)
			array[j][k] = 'a' + j + k;
	}
	printf("array **: %p\n", array);
	int z = 0;
	while (z < 13 && array[z] != 0)
	{
		printf("array[%p] = %s\n", array[z], array[z]);
		z++;
	}
	printf("------\n");
	printf("Taille de Ouille: %i\n", ft_lstsize(ouille));
	ft_printlist(ft_lstfirst(ouille));
	return (0);
}