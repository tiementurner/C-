#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>

class Zombie
{
	public:
		void 		announce(void);
					Zombie(std::string name);
					~Zombie(void);
		void 		change_name(std::string name);
	private:
		std::string name;

};

Zombie		*newZombie(std::string name);
void 		randomChump(std::string name);

#endif