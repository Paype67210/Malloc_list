#include "..:headers/malloc_list.h"

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

int	ft_lstsize(t_list *lst)
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
