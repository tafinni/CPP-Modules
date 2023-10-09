#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		std::string	modifyStr(std::string str);
		std::string	giveFirstName();
		std::string	giveLastName();
		std::string	giveNickname();
		int	startNotSpace(const std::string input);
		int	onlyNumbers(const std::string input);
		int	onlyLetters(const std::string input);
		
	public:
		int	getFirstName(std::string);
		int	getLastName(std::string);
		int	getNickname(std::string);
		int	getPhoneNumber(std::string);
		int	getSecret(std::string);
		void	displayContactInfo(Contact contacts[8], int index);
		void	displayContacts(Contact contacts[8]);
};

#endif
