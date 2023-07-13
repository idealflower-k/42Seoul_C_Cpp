/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:00:16 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/13 19:24:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string _name, int _grade)
	: name(_name), grade(_grade) {

		if (_grade > 150) {
			throw Bureaucrat::GradeTooHighException();
		} else if (_grade < 1) {
			throw Bureaucrat::GradeTooLowException();
		}
}
