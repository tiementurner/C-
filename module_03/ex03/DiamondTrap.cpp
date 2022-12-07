#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
    ClapTrap("default_clap_name"), 
    ScavTrap(), 
    FragTrap(),
    name("default")
{
    
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "Diamond constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
    ClapTrap(name + "_clap_name"), 
    ScavTrap(name),
    FragTrap(name)
{
    this->name = name;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    this->hit_points = FragTrap::hit_points;
    std::cout << "Diamond constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond destructor called." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "my name is " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}

void DiamondTrap::attack(std::string target)
{
    ScavTrap::attack(target);
}