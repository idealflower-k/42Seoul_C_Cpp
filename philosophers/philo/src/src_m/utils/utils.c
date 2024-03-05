#include "philosophers.h"
#include "defines.h"
#include "utils.h"

t_bool	ft_atouint64(const char *str, uint64_t *num)
{
	int			i;
	int			len;

	if (ft_strchr(str, '-'))
		return (FT_FALSE);
	i = 0;
	*num = 0;
	len = ft_strlen(str);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*num = (*num * 10) + (str[i] - '0');
		i++;
	}
	if (i < len)
		return (FT_FALSE);
	return (FT_TRUE);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (count && size > SIZE_MAX / count)
		return ((void *)0);
	temp = malloc(size * count);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (count * size));
	return (temp);
}
