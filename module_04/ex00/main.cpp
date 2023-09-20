#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	Dog dog;
	Cat cat;
	WrongAnimal wa;
	WrongCat wc;


	std::cout << "type = " << meta->get_type() << std::endl;
	std::cout << "type = " << j->get_type() << std::endl;
	std::cout << "type = " << i->get_type() << std::endl;
	std::cout << "type = " << wrong->get_type() << std::endl;
	std::cout << "type = " << dog.get_type() << std::endl;
	std::cout << "type = " << cat.get_type() << std::endl;
	std::cout << "type = " << wa.get_type() << std::endl;
	std::cout << "type = " << wc.get_type() << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();

	dog.makeSound();
	cat.makeSound();
	wa.makeSound();
	wc.makeSound();


	delete(j);
	delete(i);
	delete(meta);
	delete(wrong);

	return 0;


}
