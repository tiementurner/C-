#include "FragTrap.hpp"


FragTrap::FragTrap():
          ClapTrap()
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "Default Frag constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name):
          ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "Frag Name constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Frag Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &c)
{
    std::cout << "Frag Copy constructor called" << std::endl;
    *this = c;
}

FragTrap& FragTrap::operator =(const FragTrap &c)
{
    std::cout << "Frag Assignment constructor called" << std::endl;
    if (this != &c)
    {
        this->name = c.name;
        this->hit_points = c.hit_points;
        this->energy_points = c.energy_points;
        this->attack_damage = c.attack_damage;
    }
    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << this->name << " is a useless piece of trash." << std::endl;
        return ;
    }
    this->energy_points--;
    std::cout << "FragTrap " << this->name << " attacks " << target <<
                 " causing " << this->attack_damage << " points of damage!" 
                 << std::endl;
}

void FragTrap::highFivesGuy()
{
    std::cout << "Positive high fives request." << std::endl;
}