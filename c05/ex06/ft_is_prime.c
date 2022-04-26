/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:56:50 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/26 10:58:11 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	result;

	result = 0;
	i = 2;
	if (nb == 2)
		return (1);
	else if (nb < 2)
		return (0);
	while (i <= nb / 2)
	{
		if (nb % i != 0)
			{
				result = 1;
			}
		else
			return (0);
		i++;
	}
	return (result);
}
