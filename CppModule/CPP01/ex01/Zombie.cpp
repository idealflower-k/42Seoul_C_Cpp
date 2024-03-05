#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(std::string _name) {
	this->name = _name;
}

void	Zombie::announce() {
	std::cout << this->name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string _name) {
	this->name = _name;
}

Zombie::~Zombie() {
	std::cout << this->name << std::endl;
}
