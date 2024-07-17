#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	for(int i = 0; i < 10; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
}