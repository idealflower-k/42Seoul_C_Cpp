/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:43:19 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/27 14:04:15 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

typedef Base* (*FactoryFunction)();

Base*	createA() {return (new A());}
Base*	createB() {return (new B());}
Base*	createC() {return (new C());}

Base *generate(void) {
	int rand_num = std::rand() % 3;
	FactoryFunction factory_func[] = {createA, createB, createC};

	return (factory_func[rand_num]());
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "[pointer] p is A\n";
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "[pointer] p is B\n";
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "[pointer] p is C\n";
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "[reference] p is A\n";
		return ;
	} catch (std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "[reference] p is B\n";
		return ;
	} catch (std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "[reference] p is C\n";
		return ;
	} catch (std::exception& e) {}
}

int	main(void) {

	for (int i = 0; i < 10; i++) {
		Base*	some = generate();

		identify(some);
		identify(*some);
		delete some;
	}
}
