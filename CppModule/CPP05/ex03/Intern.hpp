/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:16:07 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/01 13:46:32 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Bureaucrat;

class Intern {
 private:
 public:
  Intern();
  Intern(const Intern& origin);
  Intern& operator=(const Intern& origin);

  class HaveNotForm : public std::exception {
   public:
    const char* what() const throw();
  };

  AForm* makeForm(std::string form, std::string target);

  ~Intern();
};

#endif
