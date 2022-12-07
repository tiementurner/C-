#pragma once
#include "ClapTrap.hpp"

#include <string>
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
    public: 
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator = (const ScavTrap& other);

        void attack(const std::string& target);
        void guardGate();

};