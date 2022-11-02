#include "AAnimal.hpp"

AAnimal::AAnimal() : type("beest")
{
	std::cout << "AAnimal constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& a) {
	*this = a;

	std::cout << "AAnimal copy" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &a)
{
	this->type = a.type;
	std::cout << "AAnimal assignment" << std::endl;
	return *this;
}

std::string AAnimal::get_type() const
{
	return(this->type);
}

// void AAnimal::makeSound() const
// {
// 	std::cout << "AAnimalsound" << std::endl;
// }