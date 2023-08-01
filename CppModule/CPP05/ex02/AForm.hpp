/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:26:10 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/18 13:41:18 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  const std::string name;
  bool is_signed;
  const int req_sign;
  const int req_exe;
  virtual void validGrade(int grade) const;
  AForm();

 public:
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
  class NotSignedException : public std::exception {
   public:
    const char* what() const throw();
  };

  AForm(std::string _name, int _req_sign, int _req_exe);
  AForm(const AForm& origin);

  AForm& operator=(const AForm& origin);

  void besigned(Bureaucrat& bur);
  std::string getName() const;
  int getSignGrade() const;
  int getExeGrade() const;
  bool getSigned() const;
  void validExec(Bureaucrat const& bur) const;
  virtual void execute(Bureaucrat const& executor) const = 0;

  virtual ~AForm();
};

std::ostream& operator<<(std::ostream& os, AForm& aform);

#endif
