#include "Zombie.hpp"


void mainer(Zombie* zombs)
{
	Zombie zombie_one("lsdkamd");
	zombie_one.announce();

	Zombie *zombie_two = newZombie("asadsdapper");
	zombie_two->announce();

	zombs->change_name("nice guy");

	randomChump("Chumper");
}

int main()
{
	Zombie* zombs = newZombie("prick");

	mainer(zombs);
	zombs->announce();
	delete zombs;
}

/* point of exercise:
the point of this exercise is to make a constructor class that assigns a
value to a private variable inside the class and to show that new is the 
same as malloc. So creating a zombie pointer and using "new" makes it so
the new Zombie can be used outside the function its instanciated in.
*/