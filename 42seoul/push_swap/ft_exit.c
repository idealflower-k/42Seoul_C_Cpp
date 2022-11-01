/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:06:54 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/01 20:07:33 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(const char *str, int exit_status)
{
	if (str == NULL)
	{
		perror("bash");
		exit(exit_status);
	}
	else
	{
		printf("%s\n", str);
		exit(exit_status);
	}
}
