/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:54:34 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/19 15:01:43 by sanghwal         ###   ########seoul.kr  */
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
	try {
		this->validExec(executor);
		_Robotomized(executor);
	} catch (std::exception& e) {
		throw;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << this->getName() << \
								" [RobotomyRequestForm] Destructor called\n";
}
