#include <iostream>
#include <filesystem>

#include "learningModes.hpp"


void flashcardsMode(const std::string& setName) {
    system("clear"); 
    std::cout << "Welcome to Flashcards Mode!" << std::endl;
    std::string scriptPath = "../Modes/flashcards.py"; 
    std::string command = "python " + std::filesystem::absolute(scriptPath).string() + " " + setName;
    int result = system(command.c_str());
}

void examMode(const std::string& setName) {
    system("clear"); 
    std::cout << "Welcome to Exam Mode!" << std::endl;
    std::string scriptPath = "../Modes/exam.py"; 
    std::string command = "python " + std::filesystem::absolute(scriptPath).string() + " " + setName;
    int result = system(command.c_str());
}

void quizMode(const std::string& setName) {
    system("clear"); 
    std::cout << "Welcome to Quiz Mode!" << std::endl;
    std::string scriptPath = "../Modes/quiz.py"; 
    std::string command = "python " + std::filesystem::absolute(scriptPath).string() + " " + setName;
    int result = system(command.c_str());
}

void startLearningMode(const std::string& setName) {
    system("clear"); 
    std::cout << "Choose a learning mode:" << std::endl;
    std::cout << "1. Flashcards Mode" << std::endl;
    std::cout << "2. Exam Mode [soon]" << std::endl;
    std::cout << "3. Quiz Mode [soon]" << std::endl;

    char choice;
    std::cin >> choice;

    switch (choice) {
        case '1':
            flashcardsMode(setName);
            break;
        case '2':
            examMode(setName);
            break;
        case '3':
            quizMode(setName);
            break;
        default:
            std::cout << "Invalid choice. Exiting." << std::endl;
    }
}
