#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

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
