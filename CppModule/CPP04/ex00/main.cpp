/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:02:53 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/25 20:43:31 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int	main(void) {

	const	Animal* meta = new Animal();
	const	Animal* dog = new Dog();
	const	Animal* cat = new Cat();
	
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	
	delete meta;
	delete dog;
	delete cat;

	std::cout << "===============Wrong==============" << std::endl;
	const	WrongAnimal* wrong_meta = new WrongAnimal();
	const	WrongAnimal* wrong_cat = new WrongCat();

	std::cout << wrong_cat->getType() << " " << std::endl;

	wrong_cat->makeSound();
	wrong_meta->makeSound();

	delete wrong_meta;
	delete wrong_cat;

	return (0);
}
