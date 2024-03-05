char	*ft_strstr(char *str, char *to_find)
{
	char	*p_str;
	char	*p_need;

	p_str = str;
	p_need = to_find;
	if (*to_find == 0)
		return (str);
	while (*str || *p_need == 0)
	{	
		if (*p_need == 0)
			return (p_str);
		if (*p_need == *str)
		{
			if (p_need == to_find)
				p_str = str;
			p_need++;
		}
		else
			p_need = to_find;
		str++;
	}
	return (0);
}
