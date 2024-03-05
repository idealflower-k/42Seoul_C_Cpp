#include "main.h"

int	main(int ac, char** av) {

	try {
		if (ac != 4)
			throw std::invalid_argument("arguments error");

		replaceFile(av[1], av[2], av[3]);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
