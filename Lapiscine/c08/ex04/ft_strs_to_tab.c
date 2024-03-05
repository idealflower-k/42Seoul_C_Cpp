#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*temp;
	int		len;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!temp)
		return (0);
	len = 0;
	while (*str)
		temp[len++] = *str++;
	temp[len] = 0;
	return (temp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*p_new;
	int			i;

	p_new = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!p_new)
		return (0);
	i = 0;
	while (i < ac)
	{
		p_new[i].size = ft_strlen(av[i]);
		p_new[i].str = av[i];
		p_new[i].copy = ft_strdup(av[i]);
		i++;
	}
	p_new[i].size = 0;
	p_new[i].str = 0;
	p_new[i].copy = 0;
	return (p_new);
}
