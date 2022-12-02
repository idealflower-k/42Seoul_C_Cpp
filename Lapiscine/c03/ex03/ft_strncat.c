/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:14:34 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/28 14:04:42 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_end;
	unsigned int	src_idx;
	unsigned int	size;

	size = nb;
	dest_end = 0;
	src_idx = 0;
	while (dest[dest_end])
		dest_end++;
	while (src[src_idx] && size > 0)
	{
		dest[dest_end] = src[src_idx];
		dest_end++;
		src_idx++;
		size--;
	}
	if (nb > 0)
		dest[dest_end] = 0;
	return (dest);
}
