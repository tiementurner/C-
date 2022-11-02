#include "Zombie.hpp"

Zombie::Zombie(){};
Zombie::~Zombie(){};

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string name)
{
	this->name = name;
}