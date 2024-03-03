#include <iostream>
#include <cstdlib>

#include "commands.hpp"


#define MAX_INPUT_LENGTH 1000

void init() {
    system("clear"); 
    std::cout << "Welcome to Neutrino!" << std::endl;
}

std::string getInput() {
    std::string input;
    std::getline(std::cin, input);

    return input;
}

int main() {
    std::string command;
    init();
        while (true) {
        std::cout << ">";
        command = getInput();

        if (!command.empty()) {
            execute(command.c_str());
        }
    }
    
    return 0;
}
