#include <iostream>
#include <cstdlib>
#include <cstring>
#include <filesystem>
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
    } else if (strcmp(command, "add") == 0) {
        add();
    } else if (strcmp(command, "ls") == 0) {
        showSets();
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

void help() {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "All commands:" << std::endl;
    std::cout << "help - show all commands" << std::endl;
    std::cout << "start [set] - run one of existing sets" << std::endl;
    std::cout << "add - add new set" << std::endl;
    std::cout << "exit - turn off Neutrino" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void start(const std::string& setName) {
    if (!setName.empty()) {
        std::cout << "Starting set: " << setName << std::endl;
        //to do
    } else {
        std::cerr << "Usage: start [set]" << std::endl;
    }
}

void add() {
        std::string scriptPath = "../Sets/sets.py"; 
        std::string command = "python " + std::filesystem::absolute(scriptPath).string();
        int result = system(command.c_str());
    }

void showSets() {
    const std::string setsFolder = "../Sets";
    
    // Iteruj przez wszystkie pliki w katalogu "Sets"
    for (const auto& entry : std::filesystem::directory_iterator(setsFolder)) {
        if (std::filesystem::is_regular_file(entry) && entry.path().extension() == ".db") {
            // Wyświetl nazwę pliku (bez rozszerzenia) jako set
            std::cout << "Set: " << entry.path().stem().string() << std::endl;
        }
    }
}