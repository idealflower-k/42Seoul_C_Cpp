/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:19:02 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/26 16:33:07 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **ag)
{
	int	temp;
	int	i;

	i = 0;
	temp = ac;
	while (ag[0][i])
	{
		write(1, &ag[0][i], 1);
		i++;
	}
	return (0);
}
