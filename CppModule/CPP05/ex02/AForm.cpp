/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:26:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/18 13:14:49 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
	: name(""), is_signed(false), req_sign(0), req_exe(0) {}

AForm::AForm(std::string _name, int _req_sign, int _req_exe)
	: name(_name), is_signed(false), req_sign(_req_sign), req_exe(_req_exe) {

	validGrade(_req_sign);
	validGrade(_req_exe);
}

AForm::AForm(const AForm& origin)
	: name(origin.name), is_signed(origin.is_signed),
		req_sign(origin.req_sign), req_exe(origin.req_exe) {

	validGrade(origin.req_sign);
	validGrade(origin.req_exe);
}

AForm&	AForm::operator=(const AForm& origin) {
	if (this != &origin) {
		validGrade(origin.req_sign);
		validGrade(origin.req_exe);
		const_cast<std::string&>(this->name) = origin.name;
		this->is_signed = origin.is_signed;
		const_cast<int&>(this->req_sign) = origin.req_sign;
		const_cast<int&>(this->req_exe) = origin.req_exe;
	}
	return (*this);
}

void	AForm::besigned(Bureaucrat& bur) {
	if (bur.getGrade() <= this->req_sign) {
		std::cout << "[AForm] " << bur.getName() << " signed " \
														<< this->name << "\n";
		this->is_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}

void	AForm::validGrade(int grade) const {
	if (grade > 150) {
		throw AForm::GradeTooLowException();
	} else if (grade < 1) {
		throw AForm::GradeTooHighException();
	}
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("[AForm] Grade too high!!\n");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("[AForm] Grade too low!!\n");
}

const char*	AForm::NotSignedException::what() const throw() {
	return ("[AForm] Have Not Signed\n");
}

std::string	AForm::getName(void) const {
	return (this->name);
}

int	AForm::getSignGrade(void) const {
	return (this->req_sign);
}

int	AForm::getExeGrade(void) const {
	return (this->req_exe);
}

bool	AForm::getSigned(void) const {
	return (this->is_signed);
}

void	AForm::validExec(Bureaucrat const& bur) const {
	if (!this->getSigned())
		throw AForm::NotSignedException();
	else if (bur.getGrade() > this->getExeGrade())
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, AForm& form) {
	std::cout << form.getName() + ", required  sign grade " \
		<< form.getSignGrade() << ", required execute grade " \
		<< form.getExeGrade() << ".\n";
	return (os);
}

AForm::~AForm() {
	std::cout << this->name << " [AForm] Destructor called\n";
}
