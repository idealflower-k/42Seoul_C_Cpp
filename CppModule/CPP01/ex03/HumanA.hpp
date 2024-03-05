#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA {

	private :
		Weapon&		weapon_a;
		std::string	name;

	public :
		HumanA(std::string _name, Weapon& _weapon);
		void	attack(void) const;
};

#endif
