#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog") {
	
	std::cout << "[Dog] Default constructor called" << std::endl;

	this->d_brain = new Brain();
}

Dog::Dog(const Dog& origin)
	: Animal(origin) {
	
	std::cout << "[Dog] Copy constructor called" << std::endl;
	
	this->d_brain = new Brain(*origin.d_brain);
}

Dog& Dog::operator=(const Dog& origin) {

	std::cout << "[Dog] Copy assignment called" << std::endl;
	
	if (this != &origin) {
		Animal::operator=(origin);
		*this->d_brain = *origin.d_brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "[Dog] woof!" << std::endl;
}

std::string	Dog::getType(void) const{
	std::cout << "[Dog] getType called" << std::endl;
	return (this->type);
}

Brain*	Dog::getBrain(void) {
	return (this->d_brain);
}

std::string	Dog::getIdeasIdx(int idx) const {
	return (this->d_brain->getIdeasIdx(idx));
}

void	Dog::addIdeas(const std::string& some) {
	this->d_brain->addIdeas(some);
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;

	delete this->d_brain;
}
