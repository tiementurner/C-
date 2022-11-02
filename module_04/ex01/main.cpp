#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int mainer()
{
	Dog doggy;
	Cat catty;

	Dog doggy2(doggy);
	Cat catty2;
	catty2 = catty;

	std::cout << "doggy: " << std::endl;
	doggy.get_ideas_adress();
	std::cout << "doggy2: " << std::endl;
	doggy2.get_ideas_adress();
	std::cout << "catty: " << std::endl;
	catty.get_ideas_adress();
	std::cout << "catty 2: " << std::endl;
	catty2.get_ideas_adress();


	Animal* animal_array[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			animal_array[i] = new Cat();
		else
			animal_array[i] = new Dog();
	}
	for (int i = 0 ; i < 4; i++)
	{
		std::cout << std::endl << "destroying" << std::endl;
		delete animal_array[i];
	}
	return 0;
}

int main()
{
	mainer();
	while(1);
}