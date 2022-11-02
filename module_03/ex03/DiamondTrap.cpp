#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
    ClapTrap("default_clap_name"), 
    ScavTrap(), 
    FragTrap(),
    name("default")
{
    
    this->hit_points = FragTrap::hp;
    this->energy_points = ScavTrap::ep;
    this->attack_damage = FragTrap::ad;
    std::cout << "Diamond constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
    ClapTrap(name + "_clap_name"), 
    ScavTrap(name),
    FragTrap(name)
{
    this->name = name;
    this->energy_points = ScavTrap::ep;
    this->attack_damage = FragTrap::ad;
    this->hit_points = FragTrap::hp;
    std::cout << "Diamond constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	ClapTrap::operator=(rhs);
	ScavTrap();
	FragTrap();
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