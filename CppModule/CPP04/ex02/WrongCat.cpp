#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal("WrongCat") {

	std::cout << "[WrongCat] Default constructor called" << std::endl;

	this->wc_brain = new Brain();
}

WrongCat::WrongCat(const WrongCat& origin)
	: WrongAnimal(origin.type) {

	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	this->wc_brain = origin.wc_brain;
}

WrongCat& WrongCat::operator=(const WrongCat& origin) {
	
	std::cout << "[WrongCat] Copy assignment called" << std::endl;

	if (this != &origin) {
		WrongAnimal::operator=(origin);
		this->wc_brain = origin.wc_brain;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "[WrongCat] Meow~" << std::endl;
}

std::string	WrongCat::getType(void) const {
	std::cout << "[WrongCat] getType called" << std::endl;
	return (this->type);
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called" << std::endl;
	// delete wc_brain;
}
