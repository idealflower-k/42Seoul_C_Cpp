#include "fdf.h"

void	*ft_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
		exit(1);
	ft_bzero(result, size);
	return (result);
}

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
		free(arr[i++]);
	free(arr);
}

void	free_coords(t_coord **coords, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(coords[i++]);
	free(coords);
}
