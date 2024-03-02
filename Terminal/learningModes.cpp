#include <iostream>
#include "learningModes.hpp"


void flashcardsMode(const std::string& setName) {
    system("clear"); 
    std::cout << "Welcome to Flashcards Mode!" << std::endl;
    // Add flashcards mode logic here
}

void examMode(const std::string& setName) {
    system("clear"); 
    std::cout << "Welcome to Exam Mode for set!" << std::endl;
    // Add exam mode logic here
}

void quizMode(const std::string& setName) {
    system("clear"); 
    std::cout << "Welcome to Quiz Mode for set!" << std::endl;
    // Add quiz mode logic here
}

void startLearningMode(const std::string& setName) {
    system("clear"); 
    std::cout << "Choose a learning mode:" << std::endl;
    std::cout << "1. Flashcards Mode" << std::endl;
    std::cout << "2. Exam Mode" << std::endl;
    std::cout << "3. Quiz Mode" << std::endl;

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
