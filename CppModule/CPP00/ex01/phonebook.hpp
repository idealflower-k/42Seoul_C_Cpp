/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:32 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/26 14:45:52 by sanghwal         ###   ########seoul.kr  */
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
		PhoneBook() : next_index(0), use_index(0) {}
		void	Add();
		void	Search() const;
		void	Dispay(int idx) const;
};

#endif