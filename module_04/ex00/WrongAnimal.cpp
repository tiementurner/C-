#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("beest")
{
	std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) {
	*this = a;

	std::cout << "WrongAnimal copy" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
	this->type = a.type;
	std::cout << "WrongAnimal assignment" << std::endl;
}

std::string WrongAnimal::get_type() const
{
	return(this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimalsound" << std::endl;
}