/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:09:29 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/18 17:25:22 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

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

int	main(void) {

	AForm	*rrf1 = new RobotomyRequestForm("test");

	try {
		Bureaucrat	b1("b2", 1);
		
		b1.signForm(*rrf1);
		rrf1->execute(b1);
		rrf1->execute(b1);
		rrf1->execute(b1);
		rrf1->execute(b1);
		rrf1->execute(b1);
		rrf1->execute(b1);
		rrf1->execute(b1);
		rrf1->execute(b1);
		rrf1->execute(b1);
		rrf1->execute(b1);

	} catch (std::exception& e) {
		std::cout << "Exception! " << e.what();
	}

	delete rrf1;
	return (0);
}