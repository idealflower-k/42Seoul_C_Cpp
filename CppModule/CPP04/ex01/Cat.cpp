#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat") {

	std::cout << "[Cat] Default constructor called" << std::endl;

	this->c_brain = new Brain();
}

Cat::Cat(const Cat& origin)
	: Animal(origin) {

	std::cout << "[Cat] Copy constructor called" << std::endl;

	this->c_brain = new Brain(*origin.c_brain);
}

Cat& Cat::operator=(const Cat& origin) {
	
	std::cout << "[Cat] Copy assignment called" << std::endl;

	if (this != &origin) {
		Animal::operator=(origin);
		*this->c_brain = *origin.c_brain;
	}
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "[Cat] Meow~" << std::endl;
}

std::string	Cat::getType(void) const{
	std::cout << "[Cat] getType called" << std::endl;
	return (this->type);
}

Brain*	Cat::getBrain(void) {
	return (this->c_brain);
}

std::string	Cat::getIdeasIdx(int idx) const {
	return (this->c_brain->getIdeasIdx(idx));
}

void	Cat::addIdeas(const std::string& some) {
	this->c_brain->addIdeas(some);
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;

	delete this->c_brain;
}