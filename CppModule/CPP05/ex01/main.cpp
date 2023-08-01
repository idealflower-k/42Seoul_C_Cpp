/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:54:57 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/01 13:34:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
