#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"
class HumanB
{
	public:
	void			attack();
	void			setWeapon(Weapon &weapon);
					HumanB(std::string);
					~HumanB();
	private:
	std::string 	name;
	Weapon 			*weapon;
};