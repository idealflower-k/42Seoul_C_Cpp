/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:42:25 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/26 14:06:23 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {

	private:
		const std::string	name;
		int					grade;
		void				validGrade(int grade);
		Bureaucrat();

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat& origin);

		Bureaucrat&	operator=(const Bureaucrat& origin);

		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif
