#pragma   once
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

    private:
        std::string name;
        int         hit_points;
        int         energy_points;
        int         attack_damage;
};

