#include "PhoneBook.hpp"

#include <iomanip>

std::string truncate(std::string str)
{
	if (str.length() > 9)
		return str.substr(0, 9) + '.';
	return str;
}

void PhoneBook::fill_field(int type, Contacts *contact, std::string word)
{
	int empty_line = 0;
	std::string input;

	if (std::cin.eof())
		return ;
	while(!empty_line)
	{
		std::cout << "Enter " << word << " of contact:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
		if (input.length() == 0)
		{
			empty_line = 0;
			std::cout << "empty line, please enter something\n" << std::endl;
			continue ;
		}
		contact->change_fields(type, input);
		empty_line = 1;
	}
}

void PhoneBook::add_contact(int id)
{
	Contacts contact;
	int i = 0;
	int empty_line = 0;
	std::string input;

	this->fill_field(1, &contact, "first name");
	this->fill_field(2, &contact, "last name");
	this->fill_field(3, &contact, "nick name");
	this->fill_field(4, &contact, "phone number");
	this->fill_field(5, &contact, "darkest secret");
 	contacts[id] = contact;
}

void PhoneBook::show_contacts()
{
	std::string result;

	std::cout << '\n';
	for (int j = 0; j < 8; j++)
	{
		std::cout << std::setw(10) << j + 1;
		std::cout << "|" << std::setw(10) << truncate(contacts[j].show_info(1));
		std::cout << "|" << std::setw(10) << truncate(contacts[j].show_info(2));
		std::cout << "|" << std::setw(10) << truncate(contacts[j].show_info(3));
		std::cout << "\n";
	}
	std::cout << "\nspecify contact id to display:";
	std::getline(std::cin, result);
	if (std::cin.eof())
		return ;
	if (result.length() == 1 && result[0] > '0' && result[0] < '9')
		show_contact_fields(result[0] - '0' - 1);
	else
		std::cout << "invalid input.\n";
}

void	PhoneBook::show_contact_fields(int id)
{
	std::cout << std::left << "\n" <<
	std::setw(20) << "first name: " << contacts[id].show_info(1) << "\n" <<
	std::setw(20) << "last name: " << contacts[id].show_info(2) << "\n" <<
	std::setw(20) << "nick_name: " << contacts[id].show_info(3) << "\n" <<
	std::setw(20) << "phone_number: " << contacts[id].show_info(4) << "\n" <<
	std::setw(20) << "darkest_secret: " << contacts[id].show_info(5) << "\n" << std::endl;
}

