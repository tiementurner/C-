#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>

class Zombie
{
	public:
	void		setname(std::string name);
	void 		announce();
				Zombie();
				~Zombie(void);
	private:

	std::string name;

};
void		setname(std::string name);
Zombie		*zombieHorde(int N, std::string name);

#endif