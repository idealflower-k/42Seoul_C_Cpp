#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
	std::cout << "[IMateriaSource] Default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& origin) {
	std:: cout << "[IMateriasourcr] Copy constructor called" << std::endl;
	(void)origin;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& origin) {
	
	std::cout << "[IMateriasource] Copy assignment called" << std::endl;
	
	if (this != &origin) {}

	return (*this);
}

IMateriaSource::~IMateriaSource() {
	std::cout << "[IMateriaSource] Destructor called" << std::endl;
}
