#ifndef FT_IO_H
# define FT_IO_H

# include "libft_include.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);

#endif