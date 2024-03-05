#include "minishell.h"
#include "defines.h"
#include "data_structure.h"

void	destroy(t_tree *tree)
{
	pre_order_traversal(tree->root, delete_node);
}
