/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:00:16 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 15:54:25 by sanghwal         ###   ########seoul.kr  */
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
