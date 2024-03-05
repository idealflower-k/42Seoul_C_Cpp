#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter {

	private:
		std::string			name;
		static const int	iv_size;
		AMateria**			inventory;

	public:
		Character();
		Character(const Character& origin);
		Character(const std::string _name);
		
		Character& operator=(const Character& origin);

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

		~Character();
};

#endif
