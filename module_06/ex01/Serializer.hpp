#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

struct Data
{
    int number;
};

class Serializer
{

	private:

		Serializer();
		~Serializer();
		Serializer &		operator=( Serializer const & rhs );
	public:

		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif /* ****************************************************** SERIALIZER_H */