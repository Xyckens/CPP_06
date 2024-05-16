#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	//std::cout << "Base destructor called" << std::endl;
}

Base* generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
    int random_number = rand() % 3 + 1;
	
	if (random_number == 1)
	{
		std::cout << "You randomly got the class : A!\n";
		return (new A);
	}
	else if (random_number == 2)
	{
		std::cout << "You randomly got the class : B!\n";
		return (new B);
	}
	else
	{
		std::cout << "You randomly got the class : C!\n";
		return (new C);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "This must be a class A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "This must be a class B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "This must be a class C\n";
	else
		std::cout << "Not class A, B or C\n";
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "This must be a class A\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "This must be a class B\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "This must be a class C\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}