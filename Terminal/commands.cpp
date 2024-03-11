#include <iostream>
#include <cstdlib>
#include <cstring>
#include <filesystem>

#include "commands.hpp"
#include "learningModes.hpp"

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
    } else if (strcmp(command, "start") == 0) { 
        std::string setName;
        std::cout << "Enter the name of the set you want to start learning: ";
        std::getline(std::cin, setName);
        startLearningMode(setName);
    } else if (strcmp(command, "add") == 0) {
        add();
    } else if (strcmp(command, "add-cards") == 0) {
        addCards();
    } else if (strcmp(command, "ls") == 0) {
        showSets();
    } else if (strcmp(command, "set") == 0) {
        lsSet();
    } else if (strcmp(command, "change") == 0) {
        changeName();
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
    std::cout << "exit - turn off Neutrino" << std::endl;
    std::cout << "**************** Sets ********************" << std::endl;
    std::cout << "start - run one of existing sets" << std::endl;
    std::cout << "ls - show all created sets" << std::endl;
    std::cout << "add - add new set" << std::endl;
    std::cout << "add-cards - add flashcards to set" << std::endl;
    std::cout << "set - display content of set" << std::endl;
    std::cout << "change - change the name of set" << std::endl;
    std::cout << "delete [set] - delete the set" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void add() {
        std::string scriptPath = "../Sets/add.py"; 
        std::string command = "python " + std::filesystem::absolute(scriptPath).string();
        int result = system(command.c_str());
    }

void addCards() {
        std::string scriptPath = "../Sets/addCards.py"; 
        std::string command = "python " + std::filesystem::absolute(scriptPath).string();
        int result = system(command.c_str());
}

void lsSet() {
        std::string scriptPath = "../Sets/ls.py"; 
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

void changeName() {
    std::string oldSetName;
    std::cout << "Enter the name of the set you want to change: ";
    std::getline(std::cin, oldSetName);

    const std::string setsFolder = "../Sets";
    const std::string oldSetPath = setsFolder + "/" + oldSetName + ".db";

    // Check if the set file exists
    if (std::filesystem::exists(oldSetPath)) {
        std::string newSetName;
        do {
            std::cout << "Enter the new name for the set: ";
            std::getline(std::cin, newSetName);
        } while (newSetName.empty());

        const std::string newSetPath = setsFolder + "/" + newSetName + ".db";

        // Check if the new set name already exists
        if (!std::filesystem::exists(newSetPath)) {
            // Rename the set file
            std::filesystem::rename(oldSetPath, newSetPath);
            std::cout << "Set '" << oldSetName << "' has been renamed to '" << newSetName << "'." << std::endl;
        } else {
            std::cerr << "Error: Set '" << newSetName << "' already exists." << std::endl;
        }
    } else {
        std::cerr << "Error: Set '" << oldSetName << "' not found." << std::endl;
    }
}