#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void let_sound(AAnimal *dog_or_cat)
{
	dog_or_cat->makeSound();
}

int main()
{
	Dog doggy;
	Cat catty;

	
	AAnimal *animal = new Cat();
	let_sound(animal);
	let_sound(&catty);
	delete animal;
	// Dog doggy2(doggy);
	// Cat catty2;
	// catty2 = catty;

	// std::cout << "doggy: " << std::endl;
	// doggy.get_ideas_adress();
	// std::cout << "doggy2: " << std::endl;
	// doggy2.get_ideas_adress();
	// std::cout << "catty: " << std::endl;
	// catty.get_ideas_adress();
	// std::cout << "catty 2: " << std::endl;
	// catty2.get_ideas_adress();
	// return (0);
}

