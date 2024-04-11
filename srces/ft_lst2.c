#include "../headers/malloc_list.h"

t_list	*ft_lstretrieve(t_list **lst, t_list *node)
{
	t_list	*i_token;

	i_token = *lst;
	while (i_token && i_token != node)
		i_token = i_token->next;
	if (i_token)
	{
		if (i_token->prev)
			i_token->prev->next = i_token->next;
		else
			*lst = i_token->next;
		if (i_token->next)
			i_token->next->prev = i_token->prev;
		i_token->next = NULL;
		i_token->prev = NULL;
		return (i_token);
	}
	return (NULL);
}

int	ft_lstremove(t_list **lst, t_list *node, void (*del)(void*))
{
	t_list	*i_token;

	i_token = *lst;
	while (i_token && i_token != node)
		i_token = i_token->next;
	if (i_token)
	{
		if (i_token->prev)
			i_token->prev->next = i_token->next;
		else
			*lst = i_token->next;
		if (i_token->next)
			i_token->next->prev = i_token->prev;
		ft_lstdelone(i_token, del);
		return (1);
	}
	return (0);
}

int	ft_lstreplace(t_list **lst, t_list *node)
{
	t_list	*buffer;

	buffer = *lst;
	while (buffer && buffer != node)
		buffer = buffer->next;
	if (buffer) // node was found
	{
		if (buffer->prev)
			buffer->prev->next = node;
		else
			*lst = node;
		if (buffer->next)
			buffer->next->prev = node;
		node->next = buffer->next;
		node->prev = buffer->prev;
		free(buffer);
		return (1);
	}
	return (0);
}
