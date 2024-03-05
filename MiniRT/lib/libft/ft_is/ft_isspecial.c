#include "libft.h"

bool	ft_isspecial(int c)
{
	if ((32 <= c && c <= 47) || (58 <= c && c <= 64) \
		|| (91 <= c && c <= 96) || (123 <= c && c <= 126) \
		|| ft_isspace(c))
		return (true);
	return (false);
}
