/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:52:27 by sanghwal          #+#    #+#             */
/*   Updated: 2022/05/02 16:45:08 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	cnt_word(char *str, char *charset)
{
	int	cnt_word;

	cnt_word = 0;
	while (*str)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		if (*str)
			cnt_word++;
		while (!is_charset(*str, charset) && *str)
			str++;
	}
	return (cnt_word);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str)
	{
		while (is_charset(*str, charset))
			str++;
		while (!is_charset(*str, charset))
		{
			str++;
			len++;
			if (is_charset(*(str + 1), charset))
				return (len);
		}
	}
	return (len);
}

void	str_cpy(char *result, char *str, char *charset)
{
	while (!is_charset(*str, charset))
		*result++ = *str++;
	*result = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc(sizeof(char *) * cnt_word(str, charset) + 1);
	if (!result)
		return (0);
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str == 0)
			break ;
		result[i] = (char *)malloc(sizeof(char) * word_len(str, charset) + 1);
		if (!result[i])
			return (0);
		str_cpy(result[i], str, charset);
		i++;
		while (*str && !is_charset(*str, charset))
			str++;
	}
	result[i] = 0;
	return (result);
}
