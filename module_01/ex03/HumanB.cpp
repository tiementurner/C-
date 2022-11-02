#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name){}

HumanB::~HumanB(){};

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with ";
	if (this->weapon)
		std::cout << this->weapon->getType();
	else
		std::cout << "nothing at all";
	std::cout << std::endl;
}