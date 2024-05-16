#include "Serializer.hpp"

int main()
{
	Data		*ptr1;
	Data		*ptr2;
	uintptr_t	raw;

	ptr1 = new Data;
	ptr1->raw = 13;
	
	raw = Serializer::serialize (ptr1);
	
	ptr2 = Serializer::deserialize(raw);

	std::cout << "Raw data: " << raw << std::endl;
	std::cout << "Data of ptr: " << ptr1->raw << std::endl;
	std::cout << "Data of ptr2: " << ptr2->raw << std::endl;
	delete ptr1;

	ptr1 = new Data;
	ptr1->raw = -123;
	
	raw = Serializer::serialize (ptr1);
	
	ptr2 = Serializer::deserialize(raw);

	std::cout << "\nRaw data: " << raw << std::endl;
	std::cout << "Data of ptr: " << ptr1->raw << std::endl;
	std::cout << "Data of ptr2: " << ptr2->raw << std::endl;
	delete ptr1;
	return (0);
}