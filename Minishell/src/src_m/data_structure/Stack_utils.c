#include "minishell.h"
#include "defines.h"
#include "data_structure.h"

t_bool	stack_is_empty(t_stack *stack)
{
	if (stack->size)
		return (FALSE);
	else
		return (TRUE);
}
