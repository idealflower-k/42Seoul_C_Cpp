/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:32 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/29 17:36:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	private:
		Contact contact[8];
		int		next_index;
		int		use_index;
	public:
		PhoneBook();
		void	Add();
		void	Search() const;
		void	Dispay(int idx) const;
};

#endif