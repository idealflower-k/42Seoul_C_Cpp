#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	private:
		Brain*	d_brain;

	public:
		Dog();
		Dog(const Dog& origin);
	
		Dog&		operator=(const Dog& origin);

		void		makeSound(void) const;
		std::string	getType(void) const;
		Brain*		getBrain(void);
		void		addIdeas(const std::string& some);
		std::string	getIdeasIdx(int idx) const;

		~Dog();
};

#endif
