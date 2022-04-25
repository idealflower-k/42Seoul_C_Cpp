/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:05:59 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/25 21:38:40 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int result;

	i = 1;
	result = 1;
	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}
