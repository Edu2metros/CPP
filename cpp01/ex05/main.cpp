#include <string>
#include <iostream>

class Harl{
	private:
	void debug(void){
		std::cout << "DEBUGANDO HEIN" << std::endl;
	}
	void info(void){
		std::cout << "INFORMAÇÕES" << std::endl;
	}
	void warning(void){
		std::cout << "CUIDADO HEIN" << std::endl;
	}
	void error(void){
		std::cout << "ERROR" << std::endl;
	}

	public:
	void complain(std::string level){
		struct LevelMap
		{
			std::string levelName;
			void (Harl::*function)();
		};

		LevelMap levelMap[] = 
		{
			{"debug", &Harl::debug},
			{"info", &Harl::info},
			{"warning", &Harl::warning},
			{"error", &Harl::error}	
		};

		for(int i = 0; 	i < 4; i++)
		{
			if(levelMap[i].levelName == level)
			{
				void (Harl::*function)() = levelMap[i].function;
				(this->*function)();
				return;
			}
		}
		std::cout << "NAO SEI CARAI" << std::endl;
	}
};

int main(void)
{
	Harl harl;
	harl.complain("error");
	harl.complain("bla");
	return(0);
}