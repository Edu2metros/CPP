#include "Harl.hpp"

void Harl::debug(void){
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info(void){
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}
void Harl::warning(void){
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void){
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
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

    int start = -1;

    for(int i = 0; i < 4; i++)
    {
        if(levelMap[i].levelName == level)
        {
            start = i;
            break;
        }
    }

    if(start != -1)
    {
        switch(start)
        {
            case 0:
                for(int j = 0; j < 4; j++)
                {
                    void (Harl::*function)() = levelMap[j].function;
                    (this->*function)();
                }
                break;
            case 1:
                for(int j = 1; j < 4; j++)
                {
                    void (Harl::*function)() = levelMap[j].function;
                    (this->*function)();
                }
                break;
            case 2:
                for(int j = 2; j < 4; j++)
                {
                    void (Harl::*function)() = levelMap[j].function;
                    (this->*function)();
                }
                break;
            case 3:
                for(int j = 3; j < 4; j++)
                {
                    void (Harl::*function)() = levelMap[j].function;
                    (this->*function)();
                }
                break;
        }
    }
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
