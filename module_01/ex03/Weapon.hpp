#pragma once
#include <iostream>
#include <string>

class Weapon
{
	public:
	std::string const	&getType();
	void				setType(std::string type);
						Weapon(std::string type);

	private:
	std::string type;
};


