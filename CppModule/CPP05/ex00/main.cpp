/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:18:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/26 13:22:21 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat p1("P1", 1);
		Bureaucrat p2("P2", 150);
		Bureaucrat p3("P3", 151);

		std::cout << p1;
		std::cout << p2;
		std::cout << p3;
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}

// int	main(void) {
// 	try {
// 		Bureaucrat p1("P1", 1);
// 		Bureaucrat p2("P2", 150);
// 		Bureaucrat p3("P3", 149);

// 		std::cout << p1;
// 		std::cout << p2;
// 		std::cout << p3;
// 		p2.incrementGrade();
// 		std::cout << p2;
// 		p1.incrementGrade();
// 		std::cout << p1;
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}
// 	std::cout << "After catch\n";
// 	return (0);
// }

// int	main(void) {
// 	try {
// 		Bureaucrat p1("P1", 1);
// 		Bureaucrat p2("P2", 150);
// 		Bureaucrat p3("P3", 149);

// 		std::cout << p1;
// 		std::cout << p2;
// 		std::cout << p3;
// 		p1.decrementGrade();
// 		std::cout << p2;
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}
// }

// int	main(void) {
// 	try {
// 		Bureaucrat p1("P1", 1);
// 		Bureaucrat p2("P2", 150);
// 		Bureaucrat p3("P3", 149);

// 		std::cout << p1;
// 		std::cout << p2;
// 		std::cout << p3;
		
// 		Bureaucrat p4 = p2;
// 		Bureaucrat p5(p1);

// 		std::cout << "p4 " << p4;
// 		std::cout << "p5 " << p5;
// 		p4.incrementGrade();
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}
// }
