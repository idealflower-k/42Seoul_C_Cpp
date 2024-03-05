#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*temp;
	int	i;

	i = 0;
	temp = (int *)malloc(sizeof(int) * length);
	if (!temp)
		return (0);
	while (i < length)
	{
		temp[i] = f(tab[i]);
		i++;
	}
	return (temp);
}
