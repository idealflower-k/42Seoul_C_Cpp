/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:48:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/18 19:50:44 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

#define RRF_SIGN 72
#define RRF_EXEC 45

class Aform;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& origin);

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& origin);

		void	execute(Bureaucrat const& executor) const;

		~RobotomyRequestForm();
};

#endif