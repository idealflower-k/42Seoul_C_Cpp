#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Bureaucrat b1("b1", 10);
    Bureaucrat b2("b2", 5);
    Form f1("f1", 10, 10);
    Form f2("f2", 5, 10);

    b1.signForm(f1);
    b1.signForm(f2);
    b2.signForm(f2);

    std::cout << f1;
    std::cout << f2;
  } catch (std::exception& e) {
    std::cout << e.what();
  }
}

// int	main(void) {
// 	try {

// 	Bureaucrat	b1("b1", 10);
// 	Bureaucrat	b2("b2", 5);
// 	Form		f1("f1", 10, 0);
// 	Form		f2("f2", 5, 10);

// 	b1.signForm(f1);
// 	b1.signForm(f2);
// 	b2.signForm(f2);

// 	std::cout << f1;
// 	std::cout << f2;

// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}
// }

// int	main(void) {
// 	try {

// 	Bureaucrat	b1("b1", 10);
// 	Bureaucrat	b2("b2", 151);
// 	Form		f1("f1", 10, 10);
// 	Form		f2("f2", 5, 10);

// 	b1.signForm(f1);
// 	b1.signForm(f2);
// 	b2.signForm(f2);

// 	std::cout << f1;
// 	std::cout << f2;

// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}
// }
