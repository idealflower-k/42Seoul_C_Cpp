#include "Harl.h"

int	main(void) {

	Harl	harl1;

	std::cout << "DEBUG: ";
	harl1.complain("DEBUG");

	std::cout << "INFO: ";
	harl1.complain("INFO");

	std::cout << "WARNING: ";
	harl1.complain("WARNING");

	std::cout << "ERROR: ";
	harl1.complain("ERROR");

	std::cout << "SOME: ";
	harl1.complain("SOME");
}
