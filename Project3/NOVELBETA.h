#pragma once

#include <iostream>
#include<thread>
#include<chrono>
#include <string>
#include <vector>


using namespace std;

// Structure to hold player status
struct Status {
    bool hasKeycard = false;
    bool doorOpened = false;
};

// Function to display messages with a pause
void displayMessages(const std::vector<std::string>& messages) {
    for (int i = 0; i < messages.size(); i++) {
        for (int j = 0; j < messages[i].size(); j++) {
            std::cout << messages[i][j] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

        }
        std::cout << "\n[Press Enter to continue...]\n";
        std::cin.get();
        std::cout << std::endl;
        std::cout << "\n";
    }

}

// Function to get a validated choice from the user
int getChoice(const std::vector<std::string>& options) {
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << (i + 1) << ". " << options[i] << "\n";
    }
    std::cout << "Choose an option (1-" << options.size() << "): ";

    int choice = 0;
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        try {
            choice = std::stoi(input);
            if (choice >= 1 && choice <= static_cast<int>(options.size())) {
                break;
            }
        }
        catch (...) {
            // ignore invalid input
        }
        std::cout << "Invalid input. Try again: ";
    }
    return choice - 1;  // zero-based index
}

// Panel submenu logic
void panelMenu(Status& status) {
    displayMessages({
        "SYSTEMS: CRITICAL",
        "AUTO LOCK: ENGAGED",
        "There seems to be only two buttons intact",
        });
    std::vector<std::string> panelOptions = { "Open", "Close", "Go back" };
    while (true) {
        std::cout << "\nPanel options:\n";
        int choice = getChoice(panelOptions);

        if (choice == 0) { // Open
            if (status.hasKeycard) {
                if (status.doorOpened) {
                    std::cout << "Nothing's going to change that.\n";
                }
                else {
                    std::cout << "A gush of wind enters the room.\n";
                    status.doorOpened = true;
                }
            }
            else {
                std::cout << "Access denied.\n";
            }
        }
        else if (choice == 1) { // Close
            if (status.hasKeycard) {
                std::cout << "Too late for that.\n";
            }
            else {
                std::cout << "Access denied.\n";
            }
        }
        else if (choice == 2) { // Go back
            break;  // Return to main menu
        }
    }
}

// Intro sequence
void intro(Status& status) {
    displayMessages({
        "Wake up",
        "An ear-splitting siren echoes through the icy corridors.",
        "Your head aches from the annoying noise and long sleep.",
        "Numbness slowly fades from your arms and legs, muscles and joints scream.",
        "Remember",
        "OBJECTIVE: COMPLETE THE EXPERIMENT"
        });
}

void finalSegment(Status& status);