/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:41:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/04 13:43:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

	private:	
		std::string name;

	public:
		Zombie(void);
		Zombie(std::string name);
		void	setName(std::string name);
		void	announce(void);
		~Zombie();
};

#endif
