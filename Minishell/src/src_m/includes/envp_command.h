#ifndef ENVP_COMMAND_H
# define ENVP_COMMAND_H


t_hash_elem		*hash_get(t_hash_table *ht, const char *key);
void			hash_insert(t_hash_table *ht, const char *key, const char *val);
void			hash_delete(t_hash_table *ht, const char *key);
void			hash_print_all(const char *option, t_hash_table *ht);
char			**hash_convert_arr(t_hash_table *ht);


void			free_bucket(t_hash_table *ht);
t_bool			hash_put(t_hash_elem *elem, const char *key, const char *val);
t_bool			is_same_key(const char *origin, const char *judge);
t_hash_asset	hash_asset_init(t_hash_table *ht, const char *str);
void			hash_resize(t_hash_table *ht);


t_hash_elem		*envp_receiver(\
	t_envp_flags flag, const char *key, const char *val, const char *option);


void			envp_init(char **envp);
char			*get_envp_key(char *envp_elem);
char			*get_envp_val(char *envp_elem);


void			set_envp_elem(const char *key, const char *val);
t_hash_elem		*get_envp_elem(const char *key);
void			del_envp_elem(const char *key);
void			print_envp_elem(const char *option);
char			**convert_char_arr(void);

#endif