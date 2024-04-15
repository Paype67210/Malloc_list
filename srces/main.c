/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:56 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/15 10:15:58 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc_list.h"

void	ft_printlist(t_list *list)
{
	t_list	*buffer;
	int		i=0;

	buffer = list;
	while (buffer)
	{
		printf("ouille[%i]: %p\tsize = %i\n", i++, buffer->content, buffer->size);
	 		buffer = buffer->next;
	}
}

int	main(void)
{
	t_list	*ouille;
	char	*str;
	size_t	i;

	ouille = ft_lstnew(NULL, 0);
	str = (char *)ft_malloc(&ouille, 10 * sizeof(char));
	printf("str: %p\n", str);
	for (i = 0; i < 10; i++)
		str[i] = 'a' + i;
	printf("%s\n", str);
	printf("------\n");
	if (ft_free(&ouille, str) == 1)
		printf("str a ete free\n");
	else
		printf("str n'a pas ete free\n");
	char	**array;

	array = (char **)ft_malloc(&ouille, 4 * sizeof(char *));
	printf("array: %p\n", array);
	int	j;
	for (j = 0; j < 3; j++) {
		array[j] = (char *)ft_malloc(&ouille, 11 * sizeof(char));
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
	printf("Taille de Ouille: %lu\n----------\n", ft_lstsize(ouille));
	for (j = 0; j < 3; j++) {
		if (ft_free(&ouille, array[j]) == 1)
			printf("array[%i] a ete free\n", j);
		else
			printf("array[%i] n'a pas ete free\n", j);
	}
	if (ft_free(&ouille, array) == 1)
		printf("array a ete free\n");
	else
		printf("array n'a pas ete free\n");
	printf("Taille de Ouille: %lu\n----------\n", ft_lstsize(ouille));
	int	*tab;
	tab = (int *)ft_malloc(&ouille, 30 * sizeof(int));
	printf("tab: %p\n", tab);
	for (i = 0; i < 30; i++)
		tab[i] = i;
	for (i = 0; i < 30; i++)
		printf("%i\t", tab[i]);
	printf("\nTaille de Ouille: %lu\n----------\n", ft_lstsize(ouille));
	float	*floats;
	floats = (float *)ft_malloc(&ouille, 10 * sizeof(float));
	printf("floats: %p\n", floats);
	for (i = 0; i < 10; i++)
		floats[i] = i + 0.5;
	for (i = 0; i < 10; i++)
		printf("%f\t", floats[i]);
	printf("\nTaille de Ouille: %lu\n----------\n", ft_lstsize(ouille));
	t_list	*ouille2;
	ouille2 = (t_list *)ft_malloc(&ouille, 10 * sizeof(t_list));
	printf("ouille2: %p\n", ouille2);
	printf("Taille de Ouille: %lu\n----------\ncontenu :\n", ft_lstsize(ouille));
	ft_printlist(ouille);
	if (ft_freeall(&ouille) == 1)
		printf("Tout a ete free\n");
	else
		printf("Tout n'a pas ete free\n");
	printf("FIN: Taille de Ouille: %lu\n----------\n", ft_lstsize(ouille));
	ft_printlist(ouille);
	return (0);
}
