#include "PhoneBook.hpp"

#include <iostream>

int	main(void)
{
	PhoneBook phonebook;
	std::string input = "";

	phonebook.usageInfo();
	while (input != "EXIT" && !std::cin.eof())
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input != "EXIT")
			phonebook.usageInfo();
	}
	if (input != "EXIT")
		std::cout << std::endl;
	return (0);
}
