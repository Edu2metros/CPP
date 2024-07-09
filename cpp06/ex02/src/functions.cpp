#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>



int myRand(void)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> dis(0, 2); // define the range

    return dis(gen) % 3;
}



Base *generate(void)
{
	int random = myRand();
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	std::cout << "This pointer is a ";
	if(dynamic_cast<A*>(p) != nullptr)
		std::cout << "A!" << std::endl;
	else if(dynamic_cast<B*>(p) != nullptr)
		std::cout << "B!" << std::endl;
	else if(dynamic_cast<C*>(p) != nullptr)
		std::cout << "C!" << std::endl;
	else
		std::cout << "Idk" << std::endl;
}

void identify(Base &p)
{
	std::cout << "This reference is a ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A!" << std::endl;
	}
	catch(const std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B!" << std::endl;
		}
		catch(const std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C!" << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cout << "Idk" << std::endl;
			}
		}
	}
}