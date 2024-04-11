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

char	*ft_malloc(t_list *ouille, size_t size)
{
	t_list	*head;
	void	*buffer;

	buffer = malloc(size);
	if (!buffer)
		return (NULL);
	buffer = "012345678";
	printf("Entree dans ft_malloc\tBuffer = %p\n", buffer);
	ft_lstadd_back(&ouille, ft_lstnew(buffer, size));
	printf("gdsks\n");
	head = ouille;
	return (ft_lstlast(ouille)->content);
}

int	main(void)
{
	t_list	*ouille;
	char	*str;
	int		i = -1;

	ouille = NULL;
	str = ft_malloc(ouille, 10);
	printf("str: %p\n", str);
	printf("%zu\n", ft_strlen(str));
	while (str[++i] != '\0')
		str[i] = 'a';
	printf("%s\n", (char *)str);
}