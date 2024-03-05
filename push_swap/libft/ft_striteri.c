#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	s_idx;

	if (!s || !f)
		return ;
	s_idx = 0;
	while (s[s_idx])
	{
		f(s_idx, &s[s_idx]);
		s_idx++;
	}
}
