#include "MutantStack.hpp"

int main(void)
{
	//Subject test:
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
	}

	// My own tests
	{
		MutantStack<int> stack;
		for(int i = 0; i < 10; i++)
			stack.push(i);
		MutantStack<int>::iterator it = stack.begin();
		MutantStack<int>::iterator final = stack.end();
		while (it != final)
		{	
			std::cout << *it << std::endl;
			++it;
			std::cout << "Adress of the number: " << &(*it) << std::endl;
			std::cout << "Adress of the final number: " << &(*final) << std::endl;
			// The while stops when the adress of the number is the same as the final number
		}
		std::cout << std::endl;
	}
	return 0;
}