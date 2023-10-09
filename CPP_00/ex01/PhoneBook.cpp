#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->count = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::usageInfo(void)
{
	if (std::cin.eof())
		return ;
	std::cout << 
	"----------------- PHONEBOOK -----------------\n" 
	"| >Type ADD to save a new contact           |\n"
	"| >Type SEARCH to display a specific contact|\n"
	"| >Type EXIT to quit                        |\n"
	"---------------------------------------------"
	<< std::endl;
}

void	PhoneBook::searchContact(void)
{
	Contact contact;
	std::string	input;

	std::cout << "----------------- CONTACTS ------------------" << std::endl;
	std::cout << "|  Index   |First name|Last  name| Nickname |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	contact.displayContacts(this->contacts);
	while (1)
	{
		std::cout << "SELECT CONTACT INDEX > ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input.size() == 1 && input[0] >= '1' && input[0] <= '8')
		{
		 	contact.displayContactInfo(contacts, input[0] - '0' - 1);
			break ;
		}
		else
			std::cout << "Index incorrect, give valid number" << std::endl;
	}
}

void	PhoneBook::addContact(void)
{
	Contact		contact;
	std::string	input = "";
	int			flag;

	flag = 0;
	if (this->count == 8)
	{
		this->count = 0;
		std::cout << "WARNING: starts overwriting from oldest contact" << std::endl;
	}

	while (flag == 0)
	{
		std::cout << "First name: ";
		std::getline(std::cin, input);
		flag = this->contacts[this->count].getFirstName(input);
		if (std::cin.eof())
		{
			flag = 2;
			return ;
		}
		if (flag == 0)
			std::cout << "First name must consist only of letters and can't start with empty space" << std::endl;
	}

	while (flag == 1 && !std::cin.eof())
	{
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		flag = this->contacts[this->count].getLastName(input);
		if (std::cin.eof())
		{
			flag = 2;
			return ;
		}
		if (flag == 1)
			std::cout << "Last name must consist only of letters and can't start with empty space" << std::endl;
	}

	while (flag == 0 && !std::cin.eof())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		flag = this->contacts[this->count].getNickname(input);
		if (std::cin.eof())
		{
			flag = 2;
			return ;
		}
		if (flag == 0)
			std::cout << "Input can't start with empty space" << std::endl;
	}

	while (flag == 1 && !std::cin.eof())
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		flag = this->contacts[this->count].getPhoneNumber(input);
		if (std::cin.eof())
		{
			flag = 2;
			return ;
		}
		if (flag == 1)
			std::cout << "Input must consist only of numbers and can't have empty spaces" << std::endl;
	}

	while (flag == 0 && !std::cin.eof())
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
		flag = this->contacts[this->count].getSecret(input);
		if (std::cin.eof())
		{
			flag = 2;
			return ;
		}
		if (flag == 0)
			std::cout << "Input can't start with empty space" << std::endl;
	}
	
	if (flag != 2)
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|            NEW CONTACT ADDED              |" << std::endl;
		std::cout << "---------------------------------------------\n" << std::endl;
	}
	this->count++;
}