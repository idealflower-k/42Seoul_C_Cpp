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
