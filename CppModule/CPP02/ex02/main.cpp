#include "Fixed.h"

int	main(void) {

	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}

// int main() {
//     Fixed a(10);
//     Fixed b(20);

//     // Testing > operator
//     if (a > b) {
//         std::cout << "a is greater than b" << std::endl;
//     } else {
//         std::cout << "a is not greater than b" << std::endl;
//     }

//     // Testing < operator
//     if (a < b) {
//         std::cout << "a is less than b" << std::endl;
//     } else {
//         std::cout << "a is not less than b" << std::endl;
//     }

//     // Testing >= operator
//     if (a >= b) {
//         std::cout << "a is greater than or equal to b" << std::endl;
//     } else {
//         std::cout << "a is not greater than or equal to b" << std::endl;
//     }

//     // Testing <= operator
//     if (a <= b) {
//         std::cout << "a is less than or equal to b" << std::endl;
//     } else {
//         std::cout << "a is not less than or equal to b" << std::endl;
//     }

//     // Testing == operator
//     if (a == b) {
//         std::cout << "a is equal to b" << std::endl;
//     } else {
//         std::cout << "a is not equal to b" << std::endl;
//     }

//     // Testing != operator
//     if (a != b) {
//         std::cout << "a is not equal to b" << std::endl;
//     } else {
//         std::cout << "a is equal to b" << std::endl;
//     }

//     return 0;
// }


// int main() {
//     Fixed a;

//     // Test pre-increment
//     Fixed preInc = ++a;
//     std::cout << "After pre-increment, a is " << a << ", preInc is " << preInc << std::endl;

//     // Reset a
//     a.setRawBits(0);

//     // Test post-increment
//     Fixed postInc = a++;
//     std::cout << "After post-increment, a is " << a << ", postInc is " << postInc << std::endl;

//     // Reset a
//     a.setRawBits(0);

//     // Test pre-decrement
//     Fixed preDec = --a;
//     std::cout << "After pre-decrement, a is " << a << ", preDec is " << preDec << std::endl;

//     // Reset a
//     a.setRawBits(0);

//     // Test post-decrement
//     Fixed postDec = a--;
//     std::cout << "After post-decrement, a is " << a << ", postDec is " << postDec << std::endl;

//     return 0;
// }

// int main() {
// 	Fixed a(1.5f);
// 	Fixed b(2.3f);

// 	// Test addition
// 	std::cout << "a + b = " << a + b << std::endl;

// 	// Test subtraction
// 	std::cout << "a - b = " << a - b << std::endl;

// 	// Test multiplication
// 	std::cout << "a * b = " << a * b << std::endl;

// 	// Test division
// 	try {
// 		std::cout << "a / b = " << a / b << std::endl;
// 	}
// 	catch(const std::exception& e) {
// 		std::cerr << "Caught exception: " << e.what() << std::endl;
// 	}

// 	// Test division by zero
// 	Fixed zero(0.0f);
// 	try {
// 		std::cout << "a / zero = " << a / zero << std::endl;
// 	}
// 	catch(const std::exception& e) {
// 		std::cerr << "Caught exception: " << e.what() << std::endl;
// 	}

// 	return 0;
// }
