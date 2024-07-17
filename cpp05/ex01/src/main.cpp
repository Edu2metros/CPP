#include "../include/Bureucrat.hpp"

int main(void)
{
	{ // Grade bureucrat low than te minimum
		Bureucrat GetulioVargas("Getulio Vargas", 22);
		Form Constituicao("Constituicao", 21, 20);

		GetulioVargas.signForm(Constituicao);
		std::cout << std::endl;
		std::cout << Constituicao << std::endl;
		std::cout << GetulioVargas << std::endl;
		GetulioVargas.incrementGrade();
		std::cout << GetulioVargas << std::endl;
		GetulioVargas.signForm(Constituicao);
	}
	// Grade bureucrat already signed
	{
		std::cout << std::endl << std::endl;
		Bureucrat GetulioVargas("Getulio Vargas", 20);
		Form Constituicao("Constituicao", 21, 20);

		GetulioVargas.signForm(Constituicao);
		std::cout << Constituicao << std::endl;
		std::cout << GetulioVargas << std::endl;
	}
}