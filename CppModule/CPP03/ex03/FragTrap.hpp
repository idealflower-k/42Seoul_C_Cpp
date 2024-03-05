#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "FragTrap.h"

class FragTrap : virtual public ClapTrap {

	protected:
		static const unsigned int	init_frag_hit;
		static const unsigned int	init_frag_energy;
		static const unsigned int	init_frag_attack;

	public:
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap& origin);

		FragTrap&	operator=(const FragTrap& origin);

		void		highFivesGuys(void);

		~FragTrap();
};

#endif
