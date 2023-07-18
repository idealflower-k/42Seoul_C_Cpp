/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:54:34 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/18 17:26:00 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(target, RRF_SIGN, RRF_SIGN) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
	: AForm(origin) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origin) {
	if (this != &origin)
		AForm::operator=(origin);
	return (*this);
}

static void	_Robotomized(Bureaucrat const& executor) {
	int	num = std::rand() % 2;

	if (num)
		std::cout << executor.getName() << " has been robotomized success!!\n";
	else
		std::cout << executor.getName() << " has been robotomized fail..\n";
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	this->validExec(executor);
	_Robotomized(executor);
}

void	RobotomyRequestForm::validExec(Bureaucrat const& bur) const {
	if (!this->getSigned())
		throw RobotomyRequestForm::NotSignedException();
	else if (bur.getGrade() > this->getExeGrade())
		throw RobotomyRequestForm::GradeTooLowException();
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << this->getName() << \
								" [RobotomyRequestForm] Destructor called\n";
}
