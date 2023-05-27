/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:13:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 18:37:39 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	
	private:
		static const int	learn_size;
		AMateria**			learned;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& origin);
		
		MateriaSource&	operator=(const MateriaSource& origin);
		
		void			learnMateria(AMateria* m);
		AMateria*		createMateria(std::string const& type);
		
		~MateriaSource();
};

#endif
