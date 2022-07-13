/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:16 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/13 16:20:23 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	s_len;
	size_t	s_idx;

	if (!s || !f)
		return ;
	s_len = ft_strlen(s);
	s_idx = 0;
	while (s_idx < s_len)
	{
		f(s_idx, &s[s_idx]);
		s_idx++;
	}
}
