#include "get_next_line.h"

size_t	ft_strlen(char *str);
size_t	ft_strchr(t_list *fd_list, char c);
t_list	*ft_new_list(int fd);
void	ft_del_list(t_list *fd_list);
char	*ft_strjoin(char *dst, char *src);

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!dst)
	{
		dst = (char *)malloc(sizeof(char));
		dst[0] = 0;
	}
	if (!dst || !src)
		return (0);
	result = (char *)malloc((ft_strlen(dst) + ft_strlen(src) + 1) * sizeof(char));
	if (!result)
		return (0);
	i = -1;
	j = 0;
	while (dst[++i] != 0)
		result[i] = dst[i];
	while (src[j] != 0)
		result[i++] = src[j++];
	result[i] = 0;
	free(dst);
	return (result);
}

size_t	ft_strchr(t_list *fd_list, char c)
{
	size_t	i;
	
	if (!fd_list->result)
		return (0);
	i = 0;
	while (fd_list->result[i])
	{
		if (fd_list->result[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

t_list	*ft_new_list(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new ->fd = fd;
	new ->next = 0;
	new ->result = 0;
	new ->read_byte = 1;
	new ->before = 0;
	return (new);
}

void	ft_del_list(t_list *fd_list)
{
	t_list	*temp;
	t_list	*del;

	temp = fd_list ->before;
	if (!temp)
	{
		del = fd_list;
		fd_list = fd_list ->next;
		free(del);
		return ;
	}
	temp ->next = fd_list ->next;
	free(fd_list);
}