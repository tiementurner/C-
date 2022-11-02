#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	cat_brain;
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat&	operator = (const Cat &op);

		void	get_ideas_adress();
		void	makeSound()	const;
};