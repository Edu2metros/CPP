#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2){
		std::cerr << "Invalid usage! The correct usage is: " << argv[0] << " <message>" << std::endl;
		return(1);
	}
	Harl harl;
	for(size_t i = 0; argv[1][i] != '\0'; i++){
		argv[1][i] = std::tolower(argv[1][i]);
	}
	harl.complain(argv[1]);
	return(0);
}