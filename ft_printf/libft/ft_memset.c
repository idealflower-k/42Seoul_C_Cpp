/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:25:54 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/23 17:10:07 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t len);

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)d;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (temp);
}
