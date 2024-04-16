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
	char	*str = NULL;
	size_t	i;

	str = ft_run_malloc(1, 10);
	printf("str: %p\n", str);
 	for (i = 0; i < 9; i++)
 		str[i] = 'a' + i;
 	printf("%s\n", str);
 	printf("------\n");
	if (!ft_run_malloc(2, str))
		printf("str a ete free\n");
	else
		printf("str n'a pas ete free\n");

 	char	**array = NULL;

	array = (char **)ft_run_malloc(1, 4 * sizeof(char *));
	printf("array: %p\n", array);
	int	j;
	for (j = 0; j < 3; j++) {
		array[j] = (char *)ft_run_malloc(1, 11 * sizeof(char));
		for (int k = 0; k < 10; k++)
			array[j][k] = 'a' + j + k;
	}
	printf("array **: %p\n", array);
	int z = 0;
	while (z < 3 && array[z] != 0)
	{
		printf("array[%p] = %s\n", array[z], array[z]);
		z++;
	}
	printf("------\n");
	for (j = 0; j < 3; j++) {
		if (!ft_run_malloc(2, array[j]))
			printf("array[%i] a ete free\n", j);
		else
			printf("array[%i] n'a pas ete free\n", j);
	}
	if (!ft_run_malloc(2, array))
		printf("array a ete free\n");
	else
		printf("array n'a pas ete free\n");
	
	int	*tab = NULL;
	
	tab = (int *)ft_run_malloc(1, 30 * sizeof(int));
	printf("tab: %p\n", tab);
	for (i = 0; i < 29; i++)
		tab[i] = i;
	for (i = 0; i < 29; i++)
		printf("%i\t", tab[i]);

	float	*floats = NULL;

	floats = (float *)ft_run_malloc(1, 10 * sizeof(float));
	printf("floats: %p\n", floats);
	for (i = 0; i < 10; i++)
		floats[i] = i + 0.5;
	for (i = 0; i < 10; i++)
		printf("%f\t", floats[i]);
	
	t_list	*ouille2 = NULL;
	
	ouille2 = (t_list *)ft_run_malloc(1, 10 * sizeof(t_list));
	printf("ouille2: %p\n", ouille2);
	if (!ft_run_malloc(4))
		printf("Tout a ete free\n");
	else
		printf("Tout n'a pas ete free\n");
	
	// str = ft_run_malloc(1, 10);
	// printf("str: %p\n", str);
 	// for (i = 0; i < 9; i++)
 	// 	str[i] = 'a' + i;
 	// printf("%s\n", str);
 	// printf("------\n");
	// str = ft_run_malloc(3, str, 5);
	// printf("New_str: %p\n", str);
 	// for (i = 0; i < 5; i++)
 	// 	str[i] = 'a' + i;
 	// printf("New_str: %s\n", str);
 	// printf("------\n");
	// if (!ft_run_malloc(2, str))
	// 	printf("str a ete free\n");
	// else
	// 	printf("str n'a pas ete free\n");
	return (0);
}
