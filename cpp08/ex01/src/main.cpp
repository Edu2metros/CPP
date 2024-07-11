#include "Span.hpp"

int main(void)
{
	//Subject test
	{
		Span sp = Span(6);
		sp.addNumber(2);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//Shortest span: 2 -> 3 - 5
		std::cout << sp.shortestSpan() << std::endl;
		//Longest span: 17 - 2
		std::cout << sp.longestSpan() << std::endl;
	}
	// My own tests
	{
		// Test limit
		Span sp(1);
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Test no span
		Span sp(1);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Test no range
		Span sp(1);
		try
		{
			std::vector<int> v;
			sp.addNumber(v.begin(), v.end());
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}