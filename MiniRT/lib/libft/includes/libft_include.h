#ifndef LIBFT_INCLUDE_H
# define LIBFT_INCLUDE_H


# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_list	t_list;
typedef enum e_accessor	t_accessor;


struct					s_list
{
	void				*content;
	struct s_list		*next;
};



# define FT_RAND_MAX 32767



enum					e_accessor
{
	GET,
	SET
};

#endif