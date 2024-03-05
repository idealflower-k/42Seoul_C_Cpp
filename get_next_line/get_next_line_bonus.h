#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	ssize_t			read_byte;
	char			*result;
	char			buff[BUFFER_SIZE + 1];
	struct s_list	*next;
	struct s_list	*before;
}	t_list;

char	*get_next_line(int fd);
char	*ft_read_save(t_list *list);
char	*ft_get_line(t_list *list);
char	*ft_save(t_list *list, t_list **head);
t_list	*get_list(t_list **list_head, int fd);
char	*ft_del_list(t_list *list, t_list **head);
size_t	ft_gnl_strchr(t_list *list, char c);
size_t	ft_gnl_strlen(char *str);
t_list	*ft_new_list(int fd);
char	*ft_gnl_strjoin(char *dst, char *src);

#endif