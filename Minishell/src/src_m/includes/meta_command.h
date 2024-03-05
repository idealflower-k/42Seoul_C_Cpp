#ifndef META_COMMAND_H
# define META_COMMAND_H


void			*meta_receiver(t_meta_flags flag, int arg, char *str);


t_hash_table	*get_envp(void);
t_meta			*get_meta(void);
int				get_err_num(void);
t_list			**get_unlink_lst(void);
int				*get_exit_status(void);
char			*get_cur_dir(void);
void			set_err_num(int arg);
void			set_exit_status(int arg);
void			set_cur_dir(char *str);

#endif