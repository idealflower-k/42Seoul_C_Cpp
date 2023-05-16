/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:40:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 16:16:23 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>
#include <exception>
#include <new>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

#endif
