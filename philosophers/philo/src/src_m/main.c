/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:52:58 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/28 19:54:23 by sanghwal         ###   ########seoul.kr  */
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
	create_philos();
	system("leaks philosophers");
}
