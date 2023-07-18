/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:09:29 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/18 21:31:06 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

// int	main(void) {

// 	AForm	*scf1 = new ShrubberyCreationForm("home");

// 	try {
// 		Bureaucrat	b1("b2", 1);
		
// 		b1.signForm(*scf1);
// 		scf1->execute(b1);

// 	} catch (std::exception& e) {
// 		std::cout << "Exception! " << e.what();
// 	}

// 	delete scf1;
// 	return (0);
// }

// int	main(void) {

// 	AForm	*rrf1 = new RobotomyRequestForm("test");

// 	try {
// 		Bureaucrat	b1("b2", 1);
		
// 		b1.signForm(*rrf1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);
// 		rrf1->execute(b1);

// 	} catch (std::exception& e) {
// 		std::cout << "Exception! " << e.what();
// 	}

// 	delete rrf1;
// 	return (0);
// }

// int	main(void) {
// 	AForm	*ppf1 = new PresidentialPardonForm("test ppf");
// 	try {
// 		Bureaucrat	b1("b1", 25);
// 		Bureaucrat	b2("b2", 5);

// 		b1.signForm(*ppf1);
// 		// ppf1->execute(b1);

// 		b2.executeForm(*ppf1);
// 	} catch (std::exception& e) {
// 		std::cout << "Exception! " << e.what();
// 	}

// 	delete ppf1;
// 	return (0);
// }

void check(void) {
	system("leaks Bureaucrat");
}

int main(void) {
	Intern intern1;
	AForm* form1 = NULL;
	atexit(check);
	try {
		form1 = intern1.makeForm("ShrubberyCreationForm", "home");
		if (form1) {
			Bureaucrat b1("b1", 1);
			Bureaucrat b2("b2", 150);
			b1.signForm(*form1);
			b2.executeForm(*form1);
			b1.executeForm(*form1);
		}
	} catch (std::exception& e) {
		std::cout << "Exception! " << e.what();
	}
	delete form1;
	return (0);
}
