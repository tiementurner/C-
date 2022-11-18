#include <iostream>
#include <iomanip>
#include <cstdint>

struct Data
{
    int number;
};

uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main() 
{

	uintptr_t 	raw;
	Data* 		result;
	Data* 		data;

	data = new Data;

	std::cout << "Random data: " << data << std::endl;
	raw = serialize(data);
	std::cout << "random data as uintptr: " << raw << std::endl;
	result = deserialize(raw);
	std::cout << "uintptr as data: " << result << std::endl;

	delete data;
	return 0;
}