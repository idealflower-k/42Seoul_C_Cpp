/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:21:29 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/21 20:31:07 by sanghwal         ###   ########seoul.kr  */
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
