#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap &c);
        ClapTrap& operator = (const ClapTrap &c);

        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        int         get_hit_points() const;
        int         get_energy_points() const;
        int         get_attack_damage() const;
        std::string get_name() const;


    protected:
        std::string          name;
        unsigned int         hit_points;
        unsigned int         energy_points;
        unsigned int         attack_damage;
};
