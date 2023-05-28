/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:44:08 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/28 16:42:20 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

	private:
		std::string ideas[100];
		int			next_idx;

	public:
		Brain();
		Brain(const Brain& origin);

		Brain&			operator=(const Brain& origin);

		void			addIdeas(const std::string& some);
		std::string		getIdeas(int idx) const;

		~Brain();
};

#endif
