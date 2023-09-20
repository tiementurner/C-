#include "Serializer.hpp"




int main() 
{

	uintptr_t 	raw;
	Data* 		result;
	Data* 		data;

	data = new Data;

	std::cout << "Random data: " << data << std::endl;
	raw = Serializer::serialize(data);
	std::cout << "random data as uintptr: " << raw << std::endl;
	result = Serializer::deserialize(raw);
	std::cout << "uintptr as data: " << result << std::endl;

	std::cout << sizeof(uintptr_t) << std::endl;

	delete data;
	return 0;
}