#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {

	private:
		Brain*	wc_brain;
	
	public:
		WrongCat();
		WrongCat(const WrongCat& origin);

		WrongCat&	operator=(const WrongCat& origin);

		void		makeSound(void) const;
		std::string	getType(void) const;

		~WrongCat();
};

#endif
