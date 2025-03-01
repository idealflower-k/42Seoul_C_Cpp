#include "AMateria.hpp"

AMateria::AMateria()
	: _type("\0") {

	std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type)
	: _type(type) {

	std::cout << "[AMateria] type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& origin)
	: _type(origin._type) {

	std::cout << "[AMateria] Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& origin) {

	std::cout << "[AMateria] Copy assignment constructor called" << std:: endl;

	if (this != &origin)
		this->_type = origin._type;
	return (*this);
}

std::string const& AMateria::getType() const {
	return (this->_type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "[Amateria] Nothing to use for " << target.getName() << std::endl;
}

AMateria::~AMateria() {
	std::cout << "[AMateria] Destructor called" << std::endl;
}
