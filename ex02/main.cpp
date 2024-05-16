#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
int main()
{
	Base *p = generate();
	
	identify(p);
	identify(*p);
	delete p;

	Base *a;
	a = new A();
	identify(a);
	identify(*a);
	delete a;

	Base *b;
	b = new B();
	identify(b);
	identify(*b);
	delete b;

	Base *c;
	c = new C();
	identify(c);
	identify(*c);
	delete c;	
}