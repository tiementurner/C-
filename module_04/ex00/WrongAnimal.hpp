#pragma once
#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& a);
		WrongAnimal&  operator=(const WrongAnimal& a);

		void makeSound() const;

		std::string get_type() const;

	protected:
		std::string type;
};