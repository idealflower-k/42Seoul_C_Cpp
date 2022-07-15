
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*newlst;
	t_list	*newnode;

	if (!lst || !f)
		return (0);
	cur_node = lst;
	newlst = 0;
	while (cur_node)
	{
		newnode = ft_lstnew((*f)(cur_node -> content));
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, newnode);
		cur_node = cur_node -> next;
	}
	return (newlst);
}
