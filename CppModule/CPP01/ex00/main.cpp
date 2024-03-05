#include "Zombie.h"

int	main(void) {

	Zombie *zombie1 = newZombie("zombie1");

	zombie1->announce();
	randomChump("zombie2");

	delete zombie1;

	return (0);
}
