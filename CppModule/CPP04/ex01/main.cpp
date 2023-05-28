/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:02:53 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/28 16:50:32 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// int	main(void) {
// 	Animal* j = new Dog();
// 	Animal* i = new Cat();

// 	delete j;
// 	delete i;

// 	system("leaks Animal");
// 	return(0);
// }

int main() {

	const int numAnimals = 10;

	Animal** animal_array = new Animal*[numAnimals];

	std::cout << "=====Add Dog=====" << std::endl;
	for (int i = 0; i < numAnimals / 2; ++i) {
		animal_array[i] = new Dog();
	}
	std::cout << "=====Add Cat=====" << std::endl;
	for (int i = numAnimals / 2; i < numAnimals; ++i) {
		animal_array[i] = new Cat();
	}

	std::cout << "=====Add Brain data=====" << std::endl;
	for (int i = 0; i < numAnimals; ++i) {
		std::string idea = "Idea " + std::to_string(i);
		if(i < numAnimals / 2) {
			static_cast<Dog*>(animal_array[i])->addIdeas(idea);
		} else {
			static_cast<Cat*>(animal_array[i])->addIdeas(idea);
		}
	}
	
	std::cout << "=====dispaly ideas=====" << std::endl;
	for (int i = 0; i < numAnimals; ++i) {
		if (i < numAnimals / 2) {
			std::cout << static_cast<Dog*>(animal_array[i])->getIdeas(0) << std::endl;
		}
		else
			std::cout << static_cast<Cat*>(animal_array[i])->getIdeas(0) << std::endl;
	}
	
	std::cout << "=====Delete Aniaml_array=====" << std::endl;
	for (int i = 0; i < numAnimals; ++i) {
		delete animal_array[i];
	}

	delete[] animal_array;

	system("leaks Animal");
	return 0;
}

// int	main(void) {
// 	WrongAnimal* a = new WrongCat();

// 	delete a;
// 	system("leaks Animal");
// }