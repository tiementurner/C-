#pragma once
#include <string>
#include <iostream>

class Animal
{
	public:
		Animal();
		~Animal();
		Animal(const Animal& a);
		Animal&  operator=(const Animal& a);

		virtual void makeSound() const;

		std::string get_type() const;

	protected:
		std::string type;
};