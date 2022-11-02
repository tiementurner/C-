#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int mainer()
{
	Dog doggy;
	Cat catty;
	//AAnimal animal;

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

}

int main()
{
	mainer();
	while(1);
}