#pragma once

#include <string>
#include <iostream>

class Contacts
{
public:
	std::string show_info(int n);
	void	change_fields(int type, std::string var);
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
};