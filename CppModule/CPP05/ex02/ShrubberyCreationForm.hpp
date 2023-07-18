/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:06:08 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/18 16:50:58 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
# define SCF_SIGN 145
# define SCF_EXEC 137

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		void	validExec(Bureaucrat const& bur) const;
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& origin);

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& origin);

		void	execute(Bureaucrat const& executor) const;

		~ShrubberyCreationForm();
};

#endif