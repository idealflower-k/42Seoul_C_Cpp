#include "HumanA.h"

HumanA::HumanA(std::string _name, Weapon& _weapon)
	: weapon_a(_weapon), name(_name) {}

void	HumanA::attack() const {
	std::cout << "HumanA attack : " << this->weapon_a.getType() << std::endl;
}
