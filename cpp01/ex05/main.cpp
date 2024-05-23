#include <string>
#include <iostream>

class Harl{
	private:
	void debug(void){
		std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	}
	void info(void){
		std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
	}
	void warning(void){
		std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
	}
	void error(void){
		std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
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
		std::cout << "[INVALID]\nInvalid req. Please type again." << std::endl;
	}
};

int main(void)
{
	Harl harl;
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	harl.complain("bla");
	return(0);
}