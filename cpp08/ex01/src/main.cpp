#include "Span.hpp"

int main(void)
{
	//Subject test
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//Shortest span: 11 - 9 = 2
		std::cout << sp.shortestSpan() << std::endl;
		//Longest span: 17 - 2
		std::cout << sp.longestSpan() << std::endl;
	}
	// My own tests
	{
		// Test limit
		try
		{
			Span sp(1);
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
		try
		{
			Span sp(1);
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Test no range
		try
		{
			Span sp(1);
			std::vector<int> v;
			sp.addNumber(v.begin(), v.end());
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// try to initialize a Span with a negative number or zero.
		try
		{
			Span sp(0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Span sp(-1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Test addNumber with vectors parameters
		Span sp(3);
		std::vector<int> v;
		v.push_back(1);
		v.push_back(5);
		v.push_back(300);
		sp.addNumber(v.begin(), v.end());
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		// Test addNumber with array parameters
		Span sp(3);
		int array[3] = {1, 5, 300};
		sp.addNumber(array, 3);
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}