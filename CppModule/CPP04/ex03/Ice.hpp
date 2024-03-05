#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
class Ice : public AMateria {
	
	public:
		Ice();
		Ice(const Ice& origin);
		
		Ice& operator=(const Ice& origin);

		AMateria*	clone() const;
		void		use(ICharacter& target);

		~Ice();
};

#endif
