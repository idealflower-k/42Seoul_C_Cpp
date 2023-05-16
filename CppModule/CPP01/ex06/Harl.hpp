/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:26 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 17:48:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

class Harl {

	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public :
		void	complain(std::string level);
};

#endif
