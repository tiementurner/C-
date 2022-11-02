#include "FragTrap.hpp"


FragTrap::FragTrap():
          ClapTrap()
{
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
    std::cout << "Default Frag constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name):
          ClapTrap(name)
{
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
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
    this->name = c.name;
    this->hit_points = c.get_hit_points();
    this->energy_points = c.get_energy_points();
    this->attack_damage = c.get_attack_damage();

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