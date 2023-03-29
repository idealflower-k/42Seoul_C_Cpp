/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:52:58 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/29 21:43:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "defines.h"
#include "parser.h"
#include "meta.h"

int	main(int ac, char **av)
{
	t_meta	*meta;

	if (ac < 5 && ac < 6)
		ft_print_exit("arguments error\n", 1);
	meta = get_meta(ac, av);
	// meta err 처리
	create_philos();
	system("leaks philosophers");
}
