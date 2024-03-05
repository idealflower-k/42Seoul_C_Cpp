#include "Harl.h"

int	main(int ac, char** av) {

	Harl	harl1;

	switch (ac) {
		case 1:
			std::cout << "enter the level" << std::endl;
			break ;
		case 2:
			harl1.complain(av[1]);
			break ;
		default:
			std:: cout << "enter the only one level" << std::endl;
	}
	return (0);
}