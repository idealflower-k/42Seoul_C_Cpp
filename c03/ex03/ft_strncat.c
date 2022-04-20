/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:14:34 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/20 21:22:35 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_end;
	unsigned int	src_idx;
	unsigned int	dest_idx;

	dest_end = 0;
	src_idx = 0;
	while (dest[dest_end])
		dest_end++;
	dest_idx = dest_end;
	while (src_idx < nb)
		dest[dest_idx++] = src[src_idx++];
	dest[dest_idx] = 0;
	return (dest);
}
