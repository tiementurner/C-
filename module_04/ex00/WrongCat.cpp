#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c)
{
	*this = c;

	std::cout << "copyWrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "meow" << std::endl;
}