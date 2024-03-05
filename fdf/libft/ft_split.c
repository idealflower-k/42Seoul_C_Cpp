#include "libft.h"

static size_t	ft_cnt_word(const char *s, char c);
static char		*ft_strndup(const char *s, size_t n);
static char		**ft_allfree(char **result);
char			**ft_split(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	s_idx;
	size_t	save;

	i = 0;
	s_idx = 0;
	if (!s)
		return (0);
	result = (char **)ft_calloc((ft_cnt_word(s, c) + 1), sizeof(char *));
	if (!result)
		return (0);
	while (i < ft_cnt_word(s, c) && s[s_idx] != 0)
	{
		while (s[s_idx] == c)
			s_idx++;
		save = s_idx;
		while (s[s_idx] != c && s[s_idx] != 0)
			s_idx++;
		result[i] = ft_strndup(&s[save], s_idx - save);
		if (result[i] == 0)
			return (ft_allfree(result));
		i++;
	}
	return (result);
}

static size_t	ft_cnt_word(const char *s, char c)
{
	size_t	cnt_word;
	size_t	i;

	cnt_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != c && s[i] != 0)
			cnt_word++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (cnt_word);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = 0;
	if (n == 0)
		return (0);
	temp = (char *)ft_calloc((n + 1), sizeof(char));
	if (!temp)
		return (0);
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	return (temp);
}

static	char	**ft_allfree(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return (0);
}
