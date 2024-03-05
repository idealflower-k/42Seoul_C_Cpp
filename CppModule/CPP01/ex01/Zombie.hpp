#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

	private:	
		std::string name;

	public:
		Zombie(void);
		Zombie(std::string name);
		void	setName(std::string name);
		void	announce(void);
		~Zombie();
};

#endif
