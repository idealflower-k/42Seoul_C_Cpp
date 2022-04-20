/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:22:49 by sanghwal          #+#    #+#             */
/*   Updated: 2022/04/20 23:07:18 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	check_len(char *to_find)
{
	int len;

	len = 0;
	while (to_find[len])
		len++;
	return (len);
}

unsigned int	ft_strstr(char *str, char *to_find)
{
	unsigned int	to_f_len;
	unsigned int	str_idx;
	unsigned int	to_f_idx;
	int	flag;
	int *temp;
	
	flag = 1;
	to_f_len = check_len(to_find);
	str_idx = 0;
	to_f_idx = 0;
	temp = 0;
	while (str[str_idx])
	{
		if (str[str_idx] == to_find[to_f_idx])
		{	
			temp = str[str_idx];
			while (to_f_idx < to_f_len)
			{
				if (str[str_idx] == to_find[to_f_idx])
					flag = 1;
				else
					flag = 0;
				str_idx++;
				to_f_idx++;
			}
			if (flag == 1)
				return (char *) temp;
		}
		else
			return (0);
	}
}
