/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:53:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/02 16:14:18 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char** av) {
	if (ac != 4) {std::cout << " arguments error\n"; return (1);}


	if (!replaceFile(av[1], av[2], av[3])) {
		std::cout << "replace error\n";
		return (1);
	}
	return (0);
}