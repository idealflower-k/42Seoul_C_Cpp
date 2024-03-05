#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure") {

	std::cout << "[Cure] Default constructor called" << std::endl;
}

Cure::Cure(const Cure& origin)
	: AMateria(origin) {

	this->_type = "cure";
	std::cout << "[Cure] Copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& origin) {
	
	std::cout << "[Cure] Copy assignment called" << std::endl;
	
	if (this != &origin) {
		AMateria::operator=(origin);
		this->_type = "cure";
	}
	return (*this);
}

AMateria* Cure::clone(void) const {

	AMateria* temp = new Cure(*this);
	return (temp);
}

void	Cure::use(ICharacter& target) {
	std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
}

Cure::~Cure() {
	std::cout << "[Cure] Destructor called" << std::endl;
}
