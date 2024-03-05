#include "parser_bonus.h"
#include "utils_bonus.h"

double	get_point(char *str, int *i)
{
	char	*tmp;
	int		start;
	double	res;

	if (str[*i] == '\0')
		return (0);
	start = *i;
	res = 0;
	while (str[*i] != ',' && str[*i] != '\0')
		(*i)++;
	if (*i != start)
	{
		tmp = ft_substr(str, start, *i - start);
		res = check_to_double(tmp);
		free(tmp);
	}
	(*i)++;
	return (res);
}

t_point3	parser_vec3(char *str, t_error_type err)
{
	int	i;

	if (!check_comma(str))
		error_handler(err);
	i = 0;
	if (err == RGB_ERR)
		return (rgb_init_int(
				get_point(str, &i),
				get_point(str, &i),
				get_point(str, &i)));
	else
		return (vec3_init(
				get_point(str, &i),
				get_point(str, &i),
				get_point(str, &i)));
}
