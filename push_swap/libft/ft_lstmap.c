#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlst;
	t_list	*cur_newlst;

	if (!lst || !f)
		return (0);
	newlst = ft_lstnew((*f)(lst -> content));
	if (!newlst)
		return (0);
	cur_newlst = newlst;
	lst = lst -> next;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst -> content));
		if (!temp)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		cur_newlst -> next = temp;
		cur_newlst = temp;
		lst = lst -> next;
	}
	return (newlst);
}
