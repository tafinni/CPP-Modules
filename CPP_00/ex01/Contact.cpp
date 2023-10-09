#include "Contact.hpp"

int	Contact::onlyLetters(const std::string input)
{
	std::string::const_iterator i;

	for (std::string::const_iterator i = input.begin(); i != input.end(); ++i)
		if (!std::isalpha(*i))
			return (0);
	return (1);
}

int	Contact::onlyNumbers(const std::string input)
{
	std::string::const_iterator i;

	for (std::string::const_iterator i = input.begin(); i != input.end(); ++i)
	{
		if (*i < 48 || *i > 57)
			return (0);
	}
	return (1);
}

int	Contact::startNotSpace(const std::string input)
{
	if (input.substr(0, 1).compare(" ") == 0 || input.substr(0, 1).compare("	") == 0)
		return (0);
	return (1);
}

int Contact::getFirstName(std::string input)
{
	if (!input.empty() && startNotSpace(input) == 1 && onlyLetters(input) == 1)
	{
		this->first_name = input;
		return (1);
	}
	return (0);
}

int Contact::getLastName(std::string input)
{
	if (!input.empty() && startNotSpace(input) == 1 && onlyLetters(input) == 1)
	{
		this->last_name = input;
		return (0);
	}
	return (1);
}

int Contact::getNickname(std::string input)
{
	if (!input.empty() && startNotSpace(input))
	{
		this->nickname = input;
		return (1);
	}
	return (0);
}

int Contact::getPhoneNumber(std::string input)
{
	if (!input.empty() && onlyNumbers(input) == 1 && startNotSpace(input) == 1)
	{
		this->phone_number = input;
		return (0);
	}
	return (1);
}

int Contact::getSecret(std::string input)
{
	if (!input.empty() && startNotSpace(input))
	{
		this->darkest_secret = input;
		return (1);
	}
	return (0);
}

std::string	Contact::giveFirstName(void)
{
	return (this->first_name);
}

std::string	Contact::giveLastName(void)
{
	return (this->last_name);
}

std::string	Contact::giveNickname(void)
{
	return (this->nickname);
}

void Contact::displayContactInfo(Contact contacts[8], int index)
{
	std::cout << "First name: " << contacts[index].first_name << std::endl;
	std::cout << "Last name: " << contacts[index].last_name << std::endl;
	std::cout << "Nickname: " << contacts[index].nickname << std::endl;
	std::cout << "Phone number: " << contacts[index].phone_number << std::endl;
	std::cout << "Darkest secret: " << contacts[index].darkest_secret << std::endl;
}

std::string	Contact::modifyStr(std::string str)
{	
	if (str.size() > 10)
	{
		str[9] = '.';
		str = str.substr(0, 10);
	}
	return (str);
}

void	Contact::displayContacts(Contact contacts[8])
{
	int	i;
	std::string	str = "";

	for (i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << modifyStr(contacts[i].giveFirstName());
		std::cout << "|" << std::setw(10) << modifyStr(contacts[i].giveLastName());
		std::cout << "|" << std::setw(10) << modifyStr(contacts[i].giveNickname()) << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}
