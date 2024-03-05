#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H


# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


typedef enum e_edge		t_edge;
typedef struct s_buf	t_buf;


enum e_edge {
	TAIL,
	HEAD
};


struct s_buf
{
	int				fd;
	size_t			endpoint;
	ssize_t			read_size;
	char			buf_str[BUFFER_SIZE + 1];
	t_edge			position;
	struct s_buf	*next;
};


char	*get_next_line(int fd);
void	*free_lst_elem(t_buf **buf_lst, t_buf *buf);
char	*make_str(t_buf **buf_lst, t_buf *buf);

#endif
