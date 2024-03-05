#include "HumanB.h"

HumanB::HumanB(std::string _name)
	: name(_name) {}

void	HumanB::setWeapon(Weapon& _weapon) {
	this->weapon_b = &_weapon;
}

void	HumanB::attack() const {
	std::cout << "HumanB attack : " << this->weapon_b->getType() << std::endl;
}
