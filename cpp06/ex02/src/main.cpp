#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>


int main(void)
{
	for(int i = 0; i < 10; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
}