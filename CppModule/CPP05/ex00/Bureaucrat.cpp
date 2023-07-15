/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:00:16 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/15 10:29:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

		// Bureaucrat(std::string _name, int _grade);
		// Bureaucrat(const Bureaucrat& origin);

		// Bureaucrat&	operator=(const Bureaucrat& origin);
		
		// std::string getName();
		// std::string getGrade();

		// ~Bureaucrat();

// Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string _name, int _grade)
	: name(_name), grade(_grade) {

	if (_grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	} else if (_grade < 1) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin)
	: name(origin.name), grade(origin.grade) {

	if (origin.grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	} else if (origin.grade < 1) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& origin) {
	if (this != &origin) {
		this->grade = origin.grade;
		const_cast<std::string&>(this->name) = origin.name;
	}
	return (*this);
}