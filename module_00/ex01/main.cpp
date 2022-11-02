#include "PhoneBook.hpp"


int main()
{
	std::string command;
	PhoneBook p;
	int i;

	i = 0;
	while (1)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		std::cout << "what command do you want to use? ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		if (command == "add" || command == "ADD")
		{
			if (i == 8)
				i = 0;
			p.add_contact(i);
			i++;
			continue ;
		}
		if (command == "search" || command == "SEARCH")
		{
			p.show_contacts();
			continue ;
		}
		if (command == "exit" || command == "EXIT")
			break ;
		else
			std::cout << "\nInvalid command:\nexpected: [add] || [search] || [exit]\n\n";
		
	}
}