/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:22:49 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/11 17:27:18 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*p_str;
	char	*p_need;

	p_str = str;
	p_need = to_find;
	if (*to_find == 0)
		return (str);
	while (*str || *p_need == 0)
	{	
		if (*p_need == 0)
			return (p_str);
		if (*p_need == *str)
		{
			if (p_need == to_find)
				p_str = str;
			p_need++;
		}
		else
			p_need = to_find;
		str++;
	}
	return (0);
}
