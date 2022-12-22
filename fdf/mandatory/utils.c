/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:21:29 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/22 21:31:20 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
		exit(1);
	ft_bzero(result, size);
	return (result);
}

void	free_double_arr(char **arr)
{
	int	i;
	
	i = 0;
	while (arr[i] != 0)
		free(arr[i++]);
	free(arr);
}
