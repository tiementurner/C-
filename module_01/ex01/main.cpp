#include "Zombie.hpp"



int	run()
{
	Zombie *horde = zombieHorde(5, "Chump");

	for(int i = 0; i < 5; i++)
		horde[i].announce();

	delete [] (horde);
	return (0);
}

int main()
{
	run();
	//while(1);
}