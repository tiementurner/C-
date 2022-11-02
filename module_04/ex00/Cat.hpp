#pragma once
#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(const Cat& c);
		~Cat();

		void makeSound() const;
};
