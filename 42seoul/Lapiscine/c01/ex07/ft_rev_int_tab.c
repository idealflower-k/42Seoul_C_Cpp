/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:28:12 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/19 17:39:34 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_int(int i, int j, int *tab)
{
	int	temp;

	temp = 0;
	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j <= size / 2)
	{
		swap_int(i, size - j, tab);
		i++;
		j++;
	}
}
