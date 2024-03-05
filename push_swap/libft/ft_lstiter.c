#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur_lst;

	if (!lst || !f)
		return ;
	cur_lst = lst;
	while (cur_lst)
	{
		(*f)(cur_lst -> content);
		cur_lst = cur_lst -> next;
	}
}
