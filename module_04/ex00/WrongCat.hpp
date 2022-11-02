#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat& c);
		~WrongCat();

		void makeSound() const;
};
