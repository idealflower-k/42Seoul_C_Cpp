#ifndef PARSER_H
# define PARSER_H



t_bool	set_number_of_philosophers(t_arg **args, char *av);
t_bool	set_times(t_arg **args, char **av);
t_bool	set_must_eat(t_arg **args, char *av);



void	parser_test(t_meta *meta, int ac);
void	time_test(void);

#endif