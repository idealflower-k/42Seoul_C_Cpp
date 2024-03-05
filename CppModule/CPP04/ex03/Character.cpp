#include "Character.hpp"

const int	Character::iv_size = 4;

Character::Character()
	: ICharacter(), name("Default") {

	std::cout << "[Character] Default constrctor called" << std::endl;

	this->inventory = new AMateria*[iv_size];

	for (int i = 0; i < iv_size; ++i)
		inventory[i] = NULL;
}

Character::Character(const std::string _name)
	: ICharacter(), name(_name) {

	std::cout << "[Character] name constructor called" << std::endl;

	this->inventory = new AMateria*[iv_size];

	for (int i = 0; i < iv_size; ++i)
		inventory[i] = NULL;
}

Character::Character(const Character& origin)
	: ICharacter(), name(origin.name) {
	
	std::cout << "[Character] Copy constructor called" << std::endl;
	
	this->inventory = new AMateria*[iv_size];

	for (int i = 0; i < iv_size; ++i)
		this->inventory[i] = origin.inventory[i] ? origin.inventory[i]->clone() : NULL;
}

Character& Character::operator=(const Character& origin) {
	
	std::cout << "[Character] Copy assignment called" << std::endl;

	if (this != &origin) {
		ICharacter::operator=(origin);

		for (int i = 0; i < iv_size; ++i) {
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			this->inventory[i] = origin.inventory[i] ? origin.inventory[i]->clone() : NULL;
		}

		this->name = origin.name;
	}
	return (*this);
}

std::string const&	Character::getName(void) const {
	return (this->name);
}

void	Character::equip(AMateria* m) {

	for (int i = 0; i < iv_size; ++i) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {

	if (idx >= 0 && idx < iv_size && this->inventory[idx] != NULL)
		this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx < iv_size && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}

Character::~Character() {
	std::cout << "[Character] Destructor called" << std::endl;

	for (int i = 0; i < iv_size; ++i) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	delete[] inventory;
}
