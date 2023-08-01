/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:00:16 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/01 13:32:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name(""), grade(0) {}

Bureaucrat::Bureaucrat(std::string _name, int _grade)
    : name(_name), grade(_grade) {
  this->validGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin)
    : name(origin.name), grade(origin.grade) {
  this->validGrade(origin.grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin) {
  if (this != &origin) {
    this->validGrade(origin.grade);
    this->grade = origin.grade;
    const_cast<std::string&>(this->name) = origin.name;
  }
  return (*this);
}

std::string Bureaucrat::getName(void) const { return (this->name); }

int Bureaucrat::getGrade(void) const { return (this->grade); }

void Bureaucrat::incrementGrade(void) {
  this->validGrade(this->grade - 1);
  this->grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
  this->validGrade(this->grade + 1);
  this->grade += 1;
}

void Bureaucrat::validGrade(int grade) {
  if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  } else if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade too high!! (1~150)\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade too low!! (1~150)\n");
}

void Bureaucrat::signForm(Form& form) {
  try {
    form.besigned(*this);
    std::cout << *this << "signed " << form;
  } catch (std::exception& e) {
    std::cerr << *this << "couldn't sign " << form
              << "because grade too low!\n";
  }
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
  std::cout << bureaucrat.getName() + ", bureaucrat grade "
            << bureaucrat.getGrade() << ".\n";
  return (os);
}

Bureaucrat::~Bureaucrat(void) {
  std::cout << this->name << " [Bureaucrat] Destructor called\n";
}
