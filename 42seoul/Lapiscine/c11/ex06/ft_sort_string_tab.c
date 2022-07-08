/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:10:53 by sanghwal          #+#    #+#             */
/*   Updated: 2022/05/05 10:38:04 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int		len;
	int		j;
	char	*temp;

	len = 0;
	while (tab[len])
		len++;
	while (len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		len--;
	}
}
