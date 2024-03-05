#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "ClapTrap.h"

class ClapTrap {

	private:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& origin);

		ClapTrap& operator=(const ClapTrap& origin);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		~ClapTrap();
};

#endif
