#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(const Dog& c);
		~Dog();
		Dog& operator=(const Dog& other);

		void get_ideas_adress();
		void makeSound() const;
	private:
		Brain* dog_brain;
};
