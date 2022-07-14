
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_lst;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		cur_lst = (*lst) -> next;
		ft_lstdelone(*lst, del);
		*lst = cur_lst;
	}
	*lst = 0;
}
