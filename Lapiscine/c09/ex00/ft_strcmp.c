int	ft_strcmp(char *s1, char *s2)
{
	int	curr_idx;

	curr_idx = 0;
	while (s1[curr_idx] != 0 || s2[curr_idx] != 0)
	{
		if (s1[curr_idx] != s2[curr_idx])
			return (s1[curr_idx] - s2[curr_idx]);
		curr_idx++;
	}
	return (0);
}
