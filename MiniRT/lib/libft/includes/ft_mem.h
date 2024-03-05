#ifndef FT_MEM_H
# define FT_MEM_H

# include "libft_include.h"

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_free_all_arr(char **arr);
void	ft_free_n(int n, ...);
void	*ft_malloc(size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

#endif