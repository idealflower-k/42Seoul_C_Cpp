/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:00:16 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/28 17:24:48 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {
	Zombie *zombie1 = newZombie("zombie1");

	zombie1->announce();
	randomChump("zombie2");

	delete zombie1;

	return (0);
}
