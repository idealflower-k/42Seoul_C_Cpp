
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;
	t_list	*cur_lst;

	if (!lst || !f || !del)
		return (0);
	result = 0;
	cur_lst = lst;
	while (cur_lst)
	{
		temp = ft_lstnew((*f)(cur_lst -> content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, temp);
		temp = temp -> next;
		cur_lst = cur_lst -> next;
	}
	return (result);
}
