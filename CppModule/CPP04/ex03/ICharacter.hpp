#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"
class AMateria;
class ICharacter {

	public:
		ICharacter();
		ICharacter(const ICharacter& origin);
		
		ICharacter& operator=(const ICharacter& origin);

		virtual std::string const& getName() const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;

		virtual ~ICharacter();
};

#endif
