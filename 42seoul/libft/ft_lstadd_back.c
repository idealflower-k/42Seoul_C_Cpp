
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst && !new)
		return ;
	if (!*lst && new != 0)
		*lst = new;
	else if (*lst != 0 && new != 0)
	{
		*lst = ft_lstlast(*lst);
		(*lst) -> next = new;
	}
	new -> next = 0;
}
