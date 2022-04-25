/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:39:02 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/25 21:48:26 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int result;

	result = 1;
	if (power <= 0)
		return (0);
	i = 1;
	while (i <= power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
