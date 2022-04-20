/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:53:35 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/20 21:20:00 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	dest_end;
	int	src_idx;
	int	dest_idx;

	dest_end = 0;
	src_idx = 0;
	while (dest[dest_end])
		dest_end++;
	dest_idx = dest_end;
	while (src[src_idx])
		dest[dest_idx++] = src[src_idx++];
	dest[dest_idx] = 0;
	return (dest);
}
