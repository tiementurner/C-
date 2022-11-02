#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"
class HumanA
{
	public:
	void		attack();
				HumanA(std::string, Weapon &weapon);
				~HumanA();
	private:
	std::string 	name;
	Weapon			&weapon;
};