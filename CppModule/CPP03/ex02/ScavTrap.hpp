#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ScavTrap.h"

class ScavTrap : public ClapTrap {

	protected:
		static const unsigned int	init_scav_hit;
		static const unsigned int	init_scav_energy;
		static const unsigned int	init_scav_attack;

	public:
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap& origin);

		ScavTrap&	operator=(const ScavTrap& origin);

		void		attack(const std::string& target);
		void		guardGate(void);

		~ScavTrap();
};

#endif
