#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal("WrongCat") {

	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& origin)
	: WrongAnimal(origin.type) {

	std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& origin) {
	
	std::cout << "[WrongCat] Copy assignment called" << std::endl;

	if (this != &origin)
		WrongAnimal::operator=(origin);
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
}
