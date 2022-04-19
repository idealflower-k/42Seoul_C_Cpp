/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:38:15 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/18 15:50:17 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (1);
	else
	{
		while (str[i])
		{
			if (str[i] < 97 || str[i] > 122)
				return (0);
			i++;
		}
	}
	return (1);
}
