#include "get_next_line.h"

void	ft_del_list(t_list *list);
size_t	ft_strchr(t_list *list, char c);
size_t	ft_strlen(char *str);
t_list	*ft_new_list(int fd);
char	*ft_strjoin(char *dst, char *src);

size_t	ft_strchr(t_list *list, char c)
{
	size_t	i;

	if (!list->result)
		return (0);
	i = 0;
	while (list->result[i])
	{
		if (list->result[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!dst)
	{
		dst = (char *)malloc(sizeof(char));
		if (!dst)
			return (0);
		dst[0] = 0;
	}
	result = (char *)malloc((ft_strlen(dst) + ft_strlen(src)) + 1);
	if (!result)
		return (0);
	i = -1;
	while (dst[++i] != 0)
		result[i] = dst[i];
	j = 0;
	while (src[j] != 0)
		result[i++] = src[j++];
	result[i] = 0;
	free(dst);
	dst = 0;
	return (result);
}

t_list	*ft_new_list(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->fd = fd;
	new->before = 0;
	new->next = 0;
	new->result = 0;
	new->read_byte = 1;
	return (new);
}

void	ft_del_list(t_list *list)
{
	t_list	*temp;
	t_list	*del;

	del = list;
	temp = list->before;
	if (!temp)
	{
		list->result = 0;
		list->fd = 0;
		list = list->next;
		free(del);
		del = 0;
		return ;
	}
	temp->next = list->next;
	list->result = 0;
	list->fd = 0;
	free(del);
	del = 0;
	return ;
}
