/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:20:17 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/25 21:38:07 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int sign;

	sign = 1;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
