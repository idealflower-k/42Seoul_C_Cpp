#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:
		Brain*	c_brain;

	public:
		Cat();
		Cat(const Cat& origin);

		Cat&		operator=(const Cat& origin);

		void		makeSound(void) const;
		std::string	getType(void) const;
		Brain*		getBrain(void);
		void		addIdeas(const std::string& some);
		std::string	getIdeasIdx(int idx) const;

		~Cat();
};

#endif
