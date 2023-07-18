/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:38:07 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/18 19:56:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(target, PPF_SIGN, PPF_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin)
	: AForm(origin) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origin) {
	if (this != &origin)
		AForm::operator=(origin);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	this->validExec(executor);
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << this->getName() << \
						" [PresidentialPardonForm] Destructor called\n";
}
