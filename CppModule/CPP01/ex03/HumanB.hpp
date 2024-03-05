#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {

	private :
		Weapon*		weapon_b;
		std::string	name;

	public :
		HumanB(std::string _name);
		void	setWeapon(Weapon& _weapon);
		void	attack() const;
};

#endif
