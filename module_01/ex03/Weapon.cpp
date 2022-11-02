#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon){}

std::string const &Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}