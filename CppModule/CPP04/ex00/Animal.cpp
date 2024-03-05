#include "Animal.hpp"

Animal::Animal()
	: type("\0") {

		std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(std::string _type)
	: type(_type) {

		std::cout << "[Aniaml] _type constructor called" << std::endl;
}

Animal::Animal(const Animal& origin)
	: type(origin.type) {
		
		std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& origin) {
	
	std::cout << "[Aniaml] assignment constructor called" << std:: endl;
	
	if (this != &origin) {
		this->type = origin.type;
	}
	return (*this);
}

void	Animal::makeSound(void) const{
	std::cout << "[Animal] I'm Animal!!!" << std::endl;
}

std::string	Animal::getType(void) const{
	std::cout << "[Animal] getType called" << std::endl;
	return (this->type);
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called" << std::endl;
}
