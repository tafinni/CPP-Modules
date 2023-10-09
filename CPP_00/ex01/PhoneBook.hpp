#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		count;
		void	displayContacts(Contact contacts[8]);

	public:
			PhoneBook();
			~PhoneBook();
	void	usageInfo();
	void	addContact();
	void	searchContact();
};

#endif
