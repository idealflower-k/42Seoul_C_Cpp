#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	protected:
		std::string	type;
	
	public:
		Animal();
		Animal(std::string _type);
		Animal(const Animal& origin);

		Animal&				operator=(const Animal& origin);

		virtual void		makeSound(void) const;
		virtual std::string	getType() const;

		virtual ~Animal();
};

#endif
