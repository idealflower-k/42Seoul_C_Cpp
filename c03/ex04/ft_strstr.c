/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:22:49 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/24 19:51:06 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*p_str;
	char	*p_need;

	p_str = str;
	p_need = to_find;
	while (*str)
	{	
		if (*p_need == 0)
			return (p_str);
		if (*p_need == *str)
		{
			p_need++;
			if (*p_need == *to_find)
				p_str = str;
		}
		else
			p_need = to_find;
		str++;
	}
	return (0);
}
