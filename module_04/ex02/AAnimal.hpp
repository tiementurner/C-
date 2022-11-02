#pragma once
#include <string>
#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal& a);
		AAnimal&  operator=(const AAnimal& a);

		virtual void makeSound() const = 0;

		std::string get_type() const;

	protected:
		std::string type;
};