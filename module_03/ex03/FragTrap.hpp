#pragma once
#include "ClapTrap.hpp"

#include <string>
#include <iostream>

class FragTrap : virtual public ClapTrap
{
    public: 
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap& operator = (const FragTrap& other);

        void attack(const std::string& target);
        void highFivesGuy(void);
    
    protected:
    int hp;
    int ep;
    int ad;
};