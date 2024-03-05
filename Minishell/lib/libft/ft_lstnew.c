#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = ft_malloc(sizeof(t_list));
	node -> next = (void *)0;
	node -> content = content;
	return (node);
}
