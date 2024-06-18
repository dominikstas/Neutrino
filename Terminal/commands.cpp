#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <unordered_map>
#include <functional>
#include "commands.hpp"
#include "learningModes.hpp"

void echo(const char *text);
void exitNeutrino();
void help();
void add();
void addCards();
void lsSet();
void showSets();
void deleteSet(const std::string& setName);
void changeName();
void startLearning();

void execute(const char *command) {
    std::unordered_map<std::string, std::function<void()>> commandMap = {
        {"echo", []() { 
            std::string text; 
            std::getline(std::cin, text); 
            echo(text.c_str()); 
        }},
        {"exit", exitNeutrino},
        {"help", help},
        {"start", startLearning},
        {"add", add},
        {"add-cards", addCards},
        {"ls", showSets},
        {"set", lsSet},
        {"change", changeName}
    };

    std::string cmd(command);
    if (commandMap.find(cmd) != commandMap.end()) {
        commandMap[cmd]();
    } else if (cmd.find("delete ") == 0) {
        std::string setName = cmd.substr(7);
        if (!setName.empty()) {
            deleteSet(setName);
        } else {
            std::cerr << "Usage: delete [set]" << std::endl;
        }
    } else {
        std::cout << "Unknown command: " << cmd << std::endl;
    }
}

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
    if (result != 0) {
        std::cerr << "Failed to execute add script." << std::endl;
    }
}

void addCards() {
    std::string scriptPath = "../Sets/addCards.py";
    std::string command = "python " + std::filesystem::absolute(scriptPath).string();
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Failed to execute addCards script." << std::endl;
    }
}

void lsSet() {
    std::string scriptPath = "../Sets/ls.py";
    std::string command = "python " + std::filesystem::absolute(scriptPath).string();
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Failed to execute ls script." << std::endl;
    }
}

void showSets() {
    const std::string setsFolder = "../Sets";
    int setNumber = 1;

    for (const auto& entry : std::filesystem::directory_iterator(setsFolder)) {
        if (std::filesystem::is_regular_file(entry) && entry.path().extension() == ".db") {
            std::cout << "Set " << setNumber << ": " << entry.path().stem().string() << std::endl;
            setNumber++;
        }
    }
}

void deleteSet(const std::string& setName) {
    const std::string setsFolder = "../Sets";
    const std::string setPath = setsFolder + "/" + setName + ".db";

    if (std::filesystem::exists(setPath)) {
        std::string confirmation;
        std::cout << "Are you sure you want to delete the set '" << setName << "'? (Type the set name to confirm): ";
        std::getline(std::cin, confirmation);

        if (confirmation == setName) {
            std::filesystem::remove(setPath);
            std::cout << "Set '" << setName << "' has been deleted." << std::endl;
        } else {
            std::cerr << "Deletion canceled. Set name did not match." << std::endl;
        }
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

    if (std::filesystem::exists(oldSetPath)) {
        std::string newSetName;
        do {
            std::cout << "Enter the new name for the set: ";
            std::getline(std::cin, newSetName);
        } while (newSetName.empty());

        const std::string newSetPath = setsFolder + "/" + newSetName + ".db";

        if (!std::filesystem::exists(newSetPath)) {
            std::filesystem::rename(oldSetPath, newSetPath);
            std::cout << "Set '" << oldSetName << "' has been renamed to '" << newSetName << "'." << std::endl;
        } else {
            std::cerr << "Error: Set '" << newSetName << "' already exists." << std::endl;
        }
    } else {
        std::cerr << "Error: Set '" << oldSetName << "' not found." << std::endl;
    }
}

void startLearning() {
    std::string setName;
    std::cout << "Enter the name of the set you want to start learning: ";
    std::getline(std::cin, setName);
    startLearningMode(setName);
}

int main() {
    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        execute(command.c_str());
    }
    return 0;
}
