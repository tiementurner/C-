#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap Clap1;
    ClapTrap Clap2 ("Clap2");
    FragTrap frag;
    FragTrap frag2("frag2");
    for(int i = 0; i < 5; i++)
    {
        frag2.takeDamage(10);
        frag2.attack("Clap2");
    }
    std::cout << frag2.get_name() << " has "<< frag2.get_hit_points() << " hitpoints." << std::endl;
     std::cout << frag2.get_name() << " has "<< frag2.get_energy_points() << " energy points." << std::endl;
    frag2.highFivesGuy();
}

//base class constructor is called first because the definitions of the inherited members is only in the 
//base class so to instanciate the inherited members it first needs a copy of ClapTrap so it can refer to 
//the base class data

//the destructor of the derived comes first because the base class destructor cannot refer to data from the derived class