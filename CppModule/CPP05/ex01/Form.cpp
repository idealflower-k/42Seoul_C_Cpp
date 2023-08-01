/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:26:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/01 13:31:11 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name(""), is_signed(false), req_sign(0), req_exe(0) {}

Form::Form(std::string _name, int _req_sign, int _req_exe)
    : name(_name), is_signed(false), req_sign(_req_sign), req_exe(_req_exe) {
  validGrade(_req_sign);
  validGrade(_req_exe);
}

Form::Form(const Form& origin)
    : name(origin.name),
      is_signed(origin.is_signed),
      req_sign(origin.req_sign),
      req_exe(origin.req_exe) {
  validGrade(origin.req_sign);
  validGrade(origin.req_exe);
}

Form& Form::operator=(const Form& origin) {
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

void Form::besigned(Bureaucrat& bur) {
  if (bur.getGrade() <= this->req_sign) {
    std::cout << "[Form] " << bur.getName() << " signed " << this->name << "\n";
    this->is_signed = true;
  } else
    throw Form::GradeTooLowException();
}

void Form::validGrade(int grade) {
  if (grade > 150) {
    throw Form::GradeTooLowException();
  } else if (grade < 1) {
    throw Form::GradeTooHighException();
  }
}

const char* Form::GradeTooHighException::what() const throw() {
  return ("[Form] Grade too high!! (1~150)\n");
}

const char* Form::GradeTooLowException::what() const throw() {
  return ("[Form] Grade too low!! (1~150)\n");
}

std::string Form::getName(void) const { return (this->name); }

bool Form::getSigned(void) const { return (this->is_signed); }

int Form::getSignGrade(void) const { return (this->req_sign); }

int Form::getExeGrade(void) const { return (this->req_exe); }

std::ostream& operator<<(std::ostream& os, Form& form) {
  std::cout << form.getName() + ", required  sign grade " << form.getSignGrade()
            << ", required execute grade " << form.getExeGrade() << ".\n";
  return (os);
}

Form::~Form() { std::cout << this->name << " [Form] Destructor called\n"; }
