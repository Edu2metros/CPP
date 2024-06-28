#include "../include/Bureucrat.hpp"

int main(void)
{
	Bureucrat GetulioVargas("Getulio Vargas", 22);
	Form Constituicao("Constituicao", 21, 20);

	GetulioVargas.signForm(Constituicao);
	std::cout << Constituicao << std::endl;
	std::cout << GetulioVargas << std::endl;
	GetulioVargas.incrementGrade();
	GetulioVargas.signForm(Constituicao);
}