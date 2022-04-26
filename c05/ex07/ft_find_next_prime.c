/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:58:23 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/26 10:59:15 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_prime(int nb)
{
	int i;

	i = 2;
	while (i <= nb /2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}


int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!(ft_prime(nb)))
		nb++;
	return (nb);
}
