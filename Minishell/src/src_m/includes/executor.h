#ifndef EXECUTOR_H
# define EXECUTOR_H

void				executor(t_tree *tree);



t_simple_cmd_type	is_built_in_cmd(char *cmd);


void				rdr_executor(t_tree_node *node, t_executor *execute);
void				rdr_restore(t_executor *execute);
void				pipe_executor(\
	t_tree_node *node, t_executor *execute, t_sequence sequence);
void				cmd_executor(\
	t_tree_node *node, t_executor *execute, t_sequence sequence);


t_token_type		check_token_type(t_tree_node *node);
t_bool				is_built_in(t_tree_node *root);
t_bool				is_single(t_tree_node *root);
void				shlvl_control(char *proc_name);


const char			**get_path_arr(void);
char				*make_abs_path(char *cmd, const char **path_arr);
const char			**make_envp_arr(t_tree_node *node);

#endif