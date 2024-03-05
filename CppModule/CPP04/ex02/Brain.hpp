#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

	private:
		std::string ideas[100];
		int			next_idx;

	public:
		Brain();
		Brain(const Brain& origin);

		Brain&			operator=(const Brain& origin);

		void			addIdeas(const std::string& some);
		std::string*	getIdeas(void);
		std::string		getIdeasIdx(int idx) const;

		~Brain();
};

#endif
