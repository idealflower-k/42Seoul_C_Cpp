#ifndef UTILS_H
# define UTILS_H


t_meta	*singleton(void);


void	prompt(t_meta *meta, t_tree *tree);


void	close_unlink_list(void *content);
char	*redef_cur_dir(char *prev_dir);
void	free_parser_node(t_tree_node *node);
void	clear_asset(char *line, t_tree *tree, t_meta *meta);


char	*make_prompt(char *prev_prompt);

#endif