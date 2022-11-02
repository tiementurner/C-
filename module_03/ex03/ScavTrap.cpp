#include "ScavTrap.hpp"


ScavTrap::ScavTrap():
          ClapTrap()
{
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
    std::cout << "Default Scav constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name):
          ClapTrap(name)
{
    
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
    std::cout << "Scav Name constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scav Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &c)
{
    std::cout << "Scav Copy constructor called" << std::endl;
    *this = c;
}

ScavTrap& ScavTrap::operator =(const ScavTrap &c)
{
    std::cout << "Scav Assignment constructor called" << std::endl;
    this->name = c.name;
    this->hit_points = c.get_hit_points();
    this->energy_points = c.get_energy_points();
    this->attack_damage = c.get_attack_damage();

    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << this->name << " is a useless piece of trash." << std::endl;
        return ;
    }
    this->energy_points--;
    std::cout << "ScavTrap " << this->name << " attacks " << target <<
                 " causing " << this->attack_damage << " points of damage!" 
                 << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "Scavtrap " << this->name << " is now in Gate Keeper Mode" << std::endl;
}