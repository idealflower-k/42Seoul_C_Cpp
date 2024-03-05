#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog") {
	
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& origin)
	: Animal(origin.type) {
	
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& origin) {

	std::cout << "[Dog] Copy assignment called" << std::endl;
	
	if (this != &origin)
		Animal::operator=(origin);
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "[Dog] woof!" << std::endl;
}

std::string	Dog::getType(void) const{
	std::cout << "[Dog] getType called" << std::endl;
	return (this->type);
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
}