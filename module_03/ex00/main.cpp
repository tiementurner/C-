#include "ClapTrap.hpp"

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
}