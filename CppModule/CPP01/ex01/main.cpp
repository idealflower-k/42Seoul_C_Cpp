#include "Zombie.h"

int	main(void) {

		int		n;
		Zombie* zombie_array = NULL;
	try {
		n = 5;
		zombie_array = zombieHorde(n, "arrayZombie");

		for (int i = 0; i < n; ++i)
			zombie_array[i].announce();

		delete[] zombie_array;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
