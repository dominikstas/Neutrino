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
        exitNeutrino();
    } else if (strcmp(command, "help") == 0) {
        help();
    } else if (strncmp(command, "start ", 5) == 0) {
        const char *setName = command + 6;
        start(setName);
    } else if (strcmp(command, "add") == 0) {
        add();
    } else if (strcmp(command, "ls") == 0) {
        showSets();
    } else if (strncmp(command, "delete ", 6) == 0) {
        const char *setName = command + 7;
        if (strlen(setName) > 0) {
            deleteSet(setName);
        } else {
            std::cerr << "Usage: delete [set]" << std::endl;
        }
    } else {
        std::cout << "Unknown command: " << command << std::endl;
    }
}

//that's kinda easter egg
void echo(const char *text) {
    std::cout << text << std::endl;
}

void exitNeutrino() {
    std::cout << "Thanks for using" << std::endl;
    std::exit(0);
}

void help() {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "All commands:" << std::endl;
    std::cout << "help - show all commands" << std::endl;
    std::cout << "start [set] - run one of existing sets" << std::endl;
    std::cout << "add - add new set" << std::endl;
    std::cout << "delete [set] - delete the set" << std::endl;
    std::cout << "ls - show all created sets" << std::endl;
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
        std::string scriptPath = "../Sets/add.py"; 
        std::string command = "python " + std::filesystem::absolute(scriptPath).string();
        int result = system(command.c_str());
    }

void showSets() {
    const std::string setsFolder = "../Sets";

    // Counter for numbering sets
    int setNumber = 1;

    for (const auto& entry : std::filesystem::directory_iterator(setsFolder)) {
        // Check if it's a regular file with the ".db" extension
        if (std::filesystem::is_regular_file(entry) && entry.path().extension() == ".db") {
            // Display name without extension
            std::cout << "Set " << setNumber << ": " << entry.path().stem().string() << std::endl;
            setNumber++;
        }
    }
}

void deleteSet(const std::string& setName) {
    const std::string setsFolder = "../Sets";
    const std::string setPath = setsFolder + "/" + setName + ".db";

    // Check if the set file exists
    if (std::filesystem::exists(setPath)) {
        std::filesystem::remove(setPath);
        std::cout << "Set '" << setName << "' has been deleted." << std::endl;
    } else {
        std::cerr << "Error: Set '" << setName << "' not found." << std::endl;
    }
}