/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:26:10 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/26 13:36:35 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				is_signed;
		const int			req_sign;
		const int			req_exe;
		void				validGrade(int grade);
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

		Form&		operator=(const Form& origin);
		
		void		besigned(Bureaucrat& bur);
		std::string	getName();
		bool		getSigned();
		int			getSignGrade();
		int			getExeGrade();

		~Form();
};

std::ostream& operator<<(std::ostream& os, Form& form);

#endif