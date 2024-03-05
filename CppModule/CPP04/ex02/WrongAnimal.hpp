#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	
	protected:
		std::string	type;
	
	public:
		WrongAnimal();
		WrongAnimal(std::string _type);
		WrongAnimal(const WrongAnimal& origin);

		WrongAnimal&	operator=(const WrongAnimal& origin);

		void			makeSound(void) const;
		std::string		getType(void) const;

		virtual ~WrongAnimal();
};

#endif
