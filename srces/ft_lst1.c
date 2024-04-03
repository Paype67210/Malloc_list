#include "../headers/malloc_list.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buffer;

	if (!lst)
		return (NULL);
	buffer = lst;
	while (buffer->next)
			buffer = buffer->next;
	return (buffer);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*buffer;

	if (!lst || !f || !del)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		buffer = ft_lstnew((*f)(lst->content), 0);
		if (!buffer)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, buffer);
		lst = lst->next;
	}
	return (ret);
}

t_list	*ft_lstnew(void *content, int type)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		exit (EXIT_FAILURE);
	node->content = content;
	node->type = type;
	node->next = NULL;
	node->prev = NULL;
	return (node);
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
