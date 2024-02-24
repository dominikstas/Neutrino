#include <iostream>
#include <cstdlib>
#include <cstring>
#include "commands.hpp"


void execute(const char *command) {
    if (strncmp(command, "echo ", 4) == 0) {
        const char *text = command + 5;
        if (strlen(text) > 0) {
            echo(text);
        } else {
            std::cout << "Usage: echo [text]" << std::endl;
        }
    } else if (strcmp(command, "exit") == 0) {
        exitS();
    } else if (strcmp(command, "help") == 0) {
        help();
    } else if (strncmp(command, "start ", 5) == 0) {
        const char *setName = command + 6;
        start(setName);
    } else {
        std::cout << "Unknown command: " << command << std::endl;
    }
}

void echo(const char *text) {
    std::cout << text << std::endl;
}

void exitS() {
    std::cout << "Thanks for using" << std::endl;
    std::exit(0);
}

void start(const std::string& setName) {
    if (!setName.empty()) {
        std::cout << "Starting set: " << setName << std::endl;
        // to do
    } else {
        std::cerr << "Usage: start [set]" << std::endl;
    }
}

void help() {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "All commands:" << std::endl;
    std::cout << "help - show all commands" << std::endl;
    std::cout << "start [set] - run one of existing sets" << std::endl;
    std::cout << "exit - turn off Neutrino" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}
