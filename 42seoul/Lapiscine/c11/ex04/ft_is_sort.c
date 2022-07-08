/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:24:14 by sanghwal          #+#    #+#             */
/*   Updated: 2022/05/05 10:18:08 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	temp;
	int	diff;

	i = 0;
	diff = 0;
	while (i < length - 1)
	{
		temp = f(tab[i], tab[i + 1]);
		if (temp == 0)
		{
			i++;
			continue ;
		}
		if (diff == 0)
			diff = temp;
		if ((diff > 0 && temp < 0) || (diff < 0 && temp > 0))
			return (0);
		i++;
	}
	return (1);
}
