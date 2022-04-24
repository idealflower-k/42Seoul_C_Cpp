/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:12:59 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/24 10:46:27 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	curr_idx;

	curr_idx = 0;
	while (s1[curr_idx] != 0 || s2[curr_idx] != 0)
	{
		if (s1[curr_idx] != s2[curr_idx])
		{
			if (s1[curr_idx] > s2[curr_idx])
				return (1);
			else
				return (-1);
		}
		curr_idx++;
	}
	return (0);
}
