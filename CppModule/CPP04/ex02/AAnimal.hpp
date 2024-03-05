#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {

	protected:
		std::string	type;
	
	public:
		AAnimal();
		AAnimal(std::string _type);
		AAnimal(const AAnimal& origin);

		AAnimal&			operator=(const AAnimal& origin);

		virtual void		makeSound(void) const = 0;
		virtual std::string	getType() const;

		virtual ~AAnimal();
};

#endif
