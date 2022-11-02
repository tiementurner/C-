#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap first;
    ClapTrap second("stumpertje");
    ClapTrap third(second);
    ClapTrap fourth;

    fourth = first;

    first.attack("stumpertje");
    second.takeDamage(5);
    std::cout << second.get_name() << " has " << second.get_hit_points() << "HP" << std::endl;
    second.beRepaired(3);
    std::cout << second.get_name() << " has " << second.get_hit_points() << "HP" << std::endl;
    for (int i = 0; i < 8; i++)
        second.attack("first");
    std::cout << "stumpertje has " << second.get_energy_points() << " energy points." << std::endl;
    second.attack("default");

    ScavTrap firstscav;
    ScavTrap secondscav("hoi");

    firstscav.attack("hoi");
    std::cout << "hoi has " << secondscav.get_energy_points() << " energy points." << std::endl;
    for (int i = 0; i < 8; i++)
        secondscav.attack("default");
    std::cout << "hoi has " << secondscav.get_energy_points() << " energy points." << std::endl;
    secondscav.guardGate();
}

//base class constructor is called first because the definitions of the inherited members is only in the 
//base class so to instanciate the inherited members it first needs a copy of ClapTrap so it can refer to 
//the base class data

//the destructor comes first because the base class destructor cannot refer to data from the derived class