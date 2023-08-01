/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:26:10 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/01 13:29:26 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  const std::string name;
  bool is_signed;
  const int req_sign;
  const int req_exe;
  void validGrade(int grade);
  Form();

 public:
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  Form(std::string _name, int _req_sign, int _req_exe);
  Form(const Form& origin);

  Form& operator=(const Form& origin);

  std::string getName() const;
  bool getSigned() const;
  int getSignGrade() const;
  int getExeGrade() const;
  void besigned(Bureaucrat& bur);

  ~Form();
};

std::ostream& operator<<(std::ostream& os, Form& form);

#endif
