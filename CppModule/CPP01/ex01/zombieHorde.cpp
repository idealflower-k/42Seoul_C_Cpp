#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name) {
		if (N <= 0)
			throw std::invalid_argument("invalid_N");
		
		Zombie* zombie_array = NULL;
		try {
			zombie_array = new Zombie[N];
		} catch (const std::bad_alloc& e) {
			delete[] zombie_array;
			throw;
		}

		for (int i = 0; i < N; ++i) {
			zombie_array[i].setName(name);
		}

		return (zombie_array);
}
