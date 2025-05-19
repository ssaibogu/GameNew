#include <iostream>
#include <string>
#include <vector>

// Structure to hold player status
struct Status {
    bool hasKeycard = false;
    bool doorOpened = false;
};

// Function to display messages with a pause
void displayMessages(const std::vector<std::string>& messages) {
    for (const auto& message : messages) {
        std::cout << message << "\n";
        std::cout << "[Press Enter to continue...]\n";
        std::cin.get();
        std::cout << std::endl;
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

int main() {
    Status status;
    intro(status);

    std::cout << "Look around\n";
    std::cout << "[Press Enter to continue...]\n";
    std::cin.get();

    std::vector<std::string> mainOptions = { "Panel", "Bodies", "Door", "Pods" };

    while (true) {
        std::cout << "\nWhere do you want to look?\n";
        int choice = getChoice(mainOptions);

        if (choice == 0) {  // Panel
            panelMenu(status);
        }
        else if (choice == 1) {  // Bodies
            if (!status.hasKeycard) {
                displayMessages({
        "Mutilated corpses clad in protection suits lay still in a pile in front of you",
        "Bodies are covered in huge gashes of unknown origin",
        "What could have possibly done that kind of damage?",
                    });
                std::cout << "You find a keycard on one of the bodies.\n";
                status.hasKeycard = true;
            }
            else {
                std::cout << "Nothing new here.\n";
            }
        }
        else if (choice == 2) {  // Door
            if (status.doorOpened) {
                std::cout << "I know what to do now.\n";
                displayMessages({
                    "Remember",
                    "OBJECTIVE: STOP HIM",
                    "Forward"
                    });
                break;  // Exit loop to continue story
            }
            else {
                std::cout << "The door is locked tight.\n";
            }
        }
        else if (choice == 3) {  // Pod
            displayMessages({
        "The pod where you came from is cold and empty",
        "Others are not",
                });
        }
    }

    displayMessages({
        "Each step sends impulses of pain through the body.",
        "Pain clouds up the mind."
        });

    displayMessages({
        "I MUST NOT STOP",
        "I MUST NOT STOP",
        "I MUST NOT STOP"
        });

    displayMessages({
        "With each step the corridor seems to get longer.",
        "Why do you hesitate? You know what to do.",
        "Approach the End"
        });

    displayMessages({
       "OBJECTIVE: DO NOT TRUST HIM",
       "Eyes wander in a room filled with otherworldly light",
       "The siren wail does not cease to be",
       "FOCUS YOUR EYES",
       "The source of light is right in front of me",
       "The more I look at it, the clearer my mind gets"
        });

    std::vector<std::string> finalOptions = { "Approach the End", "Approach the End", "Approach the End", "Look the other way" };

    while (true) {
        std::cout << "\nI know what to do\n";
        int choice = getChoice(finalOptions);

        if (choice >= 0 && choice <= 2) {
            std::cout << "You could still prevent it.\n\n";
            intro(status);
            break;  // restart intro and break loop
        }
        else if (choice == 3) {
            std::cout << "Resistance makes it more painful.\n\n";

            std::vector<std::string> secondFinalOptions = {
                "Approach the End", "Approach the End", "Approach the End", "Lose pain"
            };

            choice = getChoice(secondFinalOptions);

            if (choice >= 0 && choice <= 2) {
                std::cout << "You could still prevent it.\n\n";
                intro(status);
                break;
            }
            else if (choice == 3) {
                std::cout << "Why do you deny the inevitable?\n\n";

                std::vector<std::string> thirdFinalOptions = {
                    "Approach the End", "Approach the End", "Approach the End", "Lose reason"
                };

                choice = getChoice(thirdFinalOptions);

                if (choice >= 0 && choice <= 2) {
                    std::cout << "You could still prevent it.\n\n";
                    intro(status);
                    break;
                }
                else if (choice == 3) {
                    std::cout << "You will wake up again, won't you?\n\n";
                    intro(status);
                    break;
                }
            }
        }
    }

    return 0;
}