#include "Claptrap.hpp"

void check_input(int &input) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\033[1;31mInvalid input, please enter a number: \033[0m";
        std::cin >> input;
    }
}

void setup(Claptrap &claptrap) 
{
    std::cout << "\033[1;36mDo you want to configure the Class Claptrap stats? (y/n)\033[0m" << std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
		std::string name;
        int health, energy, attack;
		std::cout << "\033[1;32mEnter the name: \033[0m";
		std::cin >> name;
        std::cout << "\033[1;32mEnter the health: \033[0m";
        std::cin >> health;
        check_input(health);
        std::cout << "\033[1;32mEnter the energy: \033[0m";
        std::cin >> energy;
        check_input(energy);
        std::cout << "\033[1;32mEnter the attack: \033[0m";
        std::cin >> attack;
        check_input(attack);
        claptrap = Claptrap(name, health, energy, attack);
    } else {
        std::cout << "\033[1;33mUsing default stats!\033[0m" << std::endl;
        claptrap = Claptrap();
    }
}

void get_stats(Claptrap &claptrap) {
    std::cout << "\033[1;34mName: \033[0m" << claptrap.GetName() << std::endl;
    std::cout << "\033[1;35mHealth: \033[0m" << claptrap.GetHealth() << std::endl;
    std::cout << "\033[1;35mEnergy: \033[0m" << claptrap.GetEnergy() << std::endl;
    std::cout << "\033[1;35mAttack: \033[0m" << claptrap.GetAttack() << std::endl;
}

void display_menu() {
    std::cout << "\033[1;36mChoose an option:\033[0m" << std::endl;
    std::cout << "\033[1;33m1. Attack\033[0m" << std::endl;
    std::cout << "\033[1;33m2. Take damage\033[0m" << std::endl;
    std::cout << "\033[1;33m3. Be repaired\033[0m" << std::endl;
    std::cout << "\033[1;33m4. Show stats\033[0m" << std::endl;
    std::cout << "\033[1;33m5. Exit\033[0m" << std::endl;
}

void action(Claptrap &claptrap, int choice) {
    switch (choice) {
        case 1: {
            std::cout << "\033[1;32mWho should " << claptrap.GetName() << " attack? \033[0m";
            std::string target;
            std::cin >> target;
            claptrap.attack(target);
            break;
        }
        case 2: {
            int amount;
            std::cout << "\033[1;31mEnter the amount of damage: \033[0m";
            std::cin >> amount;
            check_input(amount);
            claptrap.takeDamage(amount);
            break;
        }
        case 3: {
            int amount;
            std::cout << "\033[1;32mEnter the amount of health to repair: \033[0m";
            std::cin >> amount;
            check_input(amount);
            claptrap.beRepaired(amount);
            break;
        }
        case 4:
            get_stats(claptrap);
            break;
        default:
            std::cout << "\033[1;31mInvalid choice!\033[0m" << std::endl;
            break;
    }
}

int main(void) {
    int choice;
    Claptrap claptrap;
    setup(claptrap);
    while (true) {
        display_menu();
        std::cin >> choice;
        check_input(choice);
        if(choice == 5)
			break;
		action(claptrap, choice);
    }
}
