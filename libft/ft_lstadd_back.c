#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else if (*lst != 0 && new != 0)
	{
		last = ft_lstlast(*lst);
		last -> next = new;
	}
}
