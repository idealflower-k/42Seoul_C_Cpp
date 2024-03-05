#include "push_swap_bonus.h"

void	free_oper_lst(t_oper *op_lst)
{
	t_oper	*tmp;
	t_oper	*del;

	del = op_lst;
	while (del != 0)
	{
		tmp = del->next;
		free(del);
		del = tmp;
	}
}

void	free_splited(char **splited)
{
	size_t	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
	return ;
}

void	free_split_lst(t_split *head)
{
	t_split	*tmp;
	t_split	*del;

	del = head;
	while (del != 0)
	{
		tmp = del->next;
		free(del);
		del = tmp;
	}
}
