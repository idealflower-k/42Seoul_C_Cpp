/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:16:07 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/26 15:52:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class Bureaucrat;

class Intern {
	private:
		Intern& operator=(const Intern& origin);

	public:
		Intern();
		Intern(const Intern& origin);

		class HaveNotForm : public std::exception {
			public:
				const char* what() const throw();
		};

		AForm*	makeForm(std::string form, std::string target);

		~Intern();
};

#endif