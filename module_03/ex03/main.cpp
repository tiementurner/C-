#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond;
    DiamondTrap rutger("rutger");

    std::cout << "attack:" << diamond.get_attack_damage() << std::endl <<
                 "energy: " << diamond.get_energy_points() << std::endl <<
                 "hitpoints:" << diamond.get_hit_points() << std::endl;
    diamond.whoAmI();
    diamond.attack("someone");

    std::cout << "attack:" << rutger.get_attack_damage() << std::endl <<
                 "energy: " << rutger.get_energy_points() << std::endl <<
                 "hitpoints:" << rutger.get_hit_points() << std::endl;
    rutger.whoAmI();
    rutger.attack("someone");

    std::cout << "energy rutger : " << rutger.get_energy_points() << std::endl;
    rutger.takeDamage(34);
    std::cout << "hitpoints rutger: " << rutger.get_hit_points() << std::endl;

    diamond = rutger;
    diamond.whoAmI();
    rutger.whoAmI();
     std::cout << "attack:" << diamond.get_attack_damage() << std::endl <<
                 "energy: " << diamond.get_energy_points() << std::endl <<
                 "hitpoints:" << diamond.get_hit_points() << std::endl;
    std::cout << "attack:" << rutger.get_attack_damage() << std::endl <<
                 "energy: " << rutger.get_energy_points() << std::endl <<
                 "hitpoints:" << rutger.get_hit_points() << std::endl;
}
