/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMeteriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:55:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 17:12:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMETERIASOURCE_HPP
# define IMETERIASOURCE_HPP

#include "IMeteriaSource.h"

class IMateriaSource {

	public:
		IMateriaSource();
		IMateriaSource(const IMateriaSource& origin);

		IMateriaSource&		operator=(const IMateriaSource& origin);

		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const& type) = 0;

		virtual ~IMateriaSource();
};

#endif
