#include "ClapTrap.hpp"


ClapTrap::ClapTrap(): 
    name("default"), 
    hit_points(10),
    energy_points(10),
    attack_damage(0)
{
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
    name(name),
    hit_points(10),
    energy_points(10),
    attack_damage(0)
{
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = c;
}

ClapTrap& ClapTrap::operator =(const ClapTrap &c)
{
    std::cout << "Assignment constructor called" << std::endl;
    this->name = c.name;
    this->hit_points = c.get_hit_points();
    this->energy_points = c.get_energy_points();
    this->attack_damage = c.get_attack_damage();

    return (*this);
}


void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << this->name << " is a useless piece of trash." << std::endl;
        return ;
    }
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " attacks " << target <<
                 " causing " << this->attack_damage << " points of damage!" 
                 << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << this->name << " is a useless piece of trash." << std::endl;
        return ;
    }
    this->energy_points--;
    this->hit_points -= amount;
    std::cout << this->name << " took " << amount << " damage points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << this->name << " is a useless piece of trash." << std::endl;
        return ;
    }
    this->energy_points--;
    this->hit_points += amount;
    std::cout << this->name << " is repaired for " << amount << " hit points!" << std::endl;
}

std::string ClapTrap::get_name() const
{
    return (this->name);
}

int ClapTrap::get_hit_points() const
{
    return(this->hit_points);
}

int ClapTrap::get_energy_points() const
{
    return(this->energy_points);
}

int ClapTrap::get_attack_damage() const
{
    return(this->attack_damage);
}