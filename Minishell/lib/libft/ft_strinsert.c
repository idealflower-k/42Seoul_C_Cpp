#include "libft.h"

char	*ft_strinsert(char **arr, char *insert)
{
	char	*str;
	char	*tmp;
	int		idx;

	idx = 0;
	str = ft_strjoin(arr[idx], "");
	while (arr[idx + 1] != NULL)
	{
		tmp = str;
		str = ft_strjoin(str, insert);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, arr[idx + 1]);
		free(tmp);
		idx++;
	}
	return (str);
}
