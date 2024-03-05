#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	private:
		Contact contact[8];
		int		next_index;
		int		use_index;
	public:
		PhoneBook();
		void	Add();
		void	Search() const;
		void	Dispay(int idx) const;
};

#endif
