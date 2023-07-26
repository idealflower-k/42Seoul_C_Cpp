/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:09:29 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/26 15:56:24 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

// int	main(void) {
// 	try {
// 		AForm	*scf1 = new ShrubberyCreationForm("home");
// 		try {
// 			Bureaucrat	b1("b2", 1);
			
// 			b1.signForm(*scf1);
// 			scf1->execute(b1);

// 		} catch (std::exception& e) {
// 			delete scf1;
// 			throw ;
// 		}
// 		delete scf1;
// 	} catch (std::exception& e) {
// 		std::cerr << "Exception! " << e.what();
// 	}
// 	return (0);
// }

// int	main(void) {
// 	try {
// 		AForm	*rrf1 = new RobotomyRequestForm("test");
// 		try {
// 			Bureaucrat	b1("b2", 1);
			
// 			b1.signForm(*rrf1);
// 			for (int i = 0; i < 10; i++)
// 				rrf1->execute(b1);
// 		} catch (std::exception& e) {
// 			delete rrf1;
// 			throw ;
// 		}
// 		delete rrf1;
// 	} catch (std::exception& e) {
// 			std::cerr << "Exception! " << e.what();
// 	}
// 	return (0);
// }

// int	main(void) {
// 	try {
// 		AForm	*ppf1 = new PresidentialPardonForm("test ppf");
// 		try {
// 			Bureaucrat	b1("b1", 25);
// 			Bureaucrat	b2("b2", 5);

// 			b1.signForm(*ppf1);
// 			// ppf1->execute(b1);

// 			b2.executeForm(*ppf1);
// 		} catch (std::exception& e) {
// 			delete ppf1;
// 		}
// 		delete ppf1;
// 	} catch (std::exception& e) {
// 		std::cerr << "Exception! " << e.what();
// 	}
// 	return (0);
// }


int main(void) {
	try {
		Intern intern1;
		AForm* form1 = NULL;
		try {
			form1 = intern1.makeForm("ShrubberyCreation", "home");
			Bureaucrat b1("b1", 1);
			Bureaucrat b2("b2", 150);
			b1.signForm(*form1);
			b2.executeForm(*form1);
			b1.executeForm(*form1);
		} catch (std::exception& e) {
			delete form1;
			throw ;
		}
		delete form1;
	} catch (std::exception& e) {
		std::cout << "Exception! " << e.what();
	}
	return (0);
}
