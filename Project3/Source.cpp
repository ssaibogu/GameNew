#include "NOVELBETA.h"
//#include <Windows.h>

string ch;

void choice();

void start() {
    //vector<string> x;

    //x.push_back({"ПРивет Андрей, попу мыл? Нет а что?\n", "Помыть попу?\n Да\n Нет\n"});
    //string a = "ПРивет Андрей, попу мыл? Нет а что?\n";

 /*   for (int i = 0; i < x[0].size(); i++) {
        std::cout << x[0][i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }

    string b = "Помыть попу?\n Да\n Нет\n";

    for (int i = 0; i < b.size(); i++) {
        std::cout << b[i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }*/
    displayMessages({ "ПРивет Андрей, попу мыл? Нет а что?\n", "Помыть попу?\n Да\n Нет\n" });

    choice();

}

void choice() {
    cin >> ch;

    if (ch == "Да") {

        cout << "*Грузин молча тушит свечку*\n";

    }
    else if (ch == "Нет") {
    
        cout << "Вернись с мытой.\n";
    }
    else {
        cout << "ERROR\n";
        return choice();

    }

}


int main() {
    setlocale(LC_ALL, "Russian");
    //SetConsoleCP(1251);

    start();

    //Status status;
    //intro(status);

    //std::cout << "Look around\n";
    //std::cout << "[Press Enter to continue...]\n";
    //std::cin.get();

    //std::vector<std::string> mainOptions = { "Panel", "Bodies", "Door", "Pods" };

    //while (true) {
    //    std::cout << "\nWhere do you want to look?\n";
    //    int choice = getChoice(mainOptions);

    //    if (choice == 0) {  // Panel
    //        panelMenu(status);
    //    }
    //    else if (choice == 1) {  // Bodies
    //        if (!status.hasKeycard) {
    //            displayMessages({
    //    "Mutilated corpses clad in protection suits lay still in a pile in front of you",
    //    "Bodies are covered in huge gashes of unknown origin",
    //    "What could have possibly done that kind of damage?",
    //                });
    //            std::cout << "You find a keycard on one of the bodies.\n";
    //            status.hasKeycard = true;
    //        }
    //        else {
    //            std::cout << "Nothing new here.\n";
    //        }
    //    }
    //    else if (choice == 2) {  // Door
    //        if (status.doorOpened) {
    //            std::cout << "I know what to do now.\n";
    //            displayMessages({
    //                "Remember",
    //                "OBJECTIVE: STOP HIM",
    //                "Forward"
    //                });
    //            break;  // Exit loop to continue story
    //        }
    //        else {
    //            std::cout << "The door is locked tight.\n";
    //        }
    //    }
    //    else if (choice == 3) {  // Pod
    //        displayMessages({
    //    "The pod where you came from is cold and empty",
    //    "Others are not",
    //            });
    //    }
    //}

    //displayMessages({
    //    "Each step sends impulses of pain through the body.",
    //    "Pain clouds up the mind."
    //    });

    //displayMessages({
    //    "I MUST NOT STOP",
    //    "I MUST NOT STOP",
    //    "I MUST NOT STOP"
    //    });

    //displayMessages({
    //    "With each step the corridor seems to get longer.",
    //    "Why do you hesitate? You know what to do.",
    //    "Approach the End"
    //    });

    //displayMessages({
    //   "OBJECTIVE: DO NOT TRUST HIM",
    //   "Eyes wander in a room filled with otherworldly light",
    //   "The siren wail does not cease to be",
    //   "FOCUS YOUR EYES",
    //   "The source of light is right in front of me",
    //   "The more I look at it, the clearer my mind gets"
    //    });

    //std::vector<std::string> finalOptions = { "Approach the End", "Approach the End", "Approach the End", "Look the other way" };

    //while (true) {
    //    std::cout << "\nI know what to do\n";
    //    int choice = getChoice(finalOptions);

    //    if (choice >= 0 && choice <= 2) {
    //        std::cout << "You could still prevent it.\n\n";
    //        intro(status);
    //        break;  // restart intro and break loop
    //    }
    //    else if (choice == 3) {
    //        std::cout << "Resistance makes it more painful.\n\n";

    //        std::vector<std::string> secondFinalOptions = {
    //            "Approach the End", "Approach the End", "Approach the End", "Lose pain"
    //        };

    //        choice = getChoice(secondFinalOptions);

    //        if (choice >= 0 && choice <= 2) {
    //            std::cout << "You could still prevent it.\n\n";
    //            intro(status);
    //            break;
    //        }
    //        else if (choice == 3) {
    //            std::cout << "Why do you deny the inevitable?\n\n";

    //            std::vector<std::string> thirdFinalOptions = {
    //                "Approach the End", "Approach the End", "Approach the End", "Lose reason"
    //            };

    //            choice = getChoice(thirdFinalOptions);

    //            if (choice >= 0 && choice <= 2) {
    //                std::cout << "You could still prevent it.\n\n";
    //                intro(status);
    //                break;
    //            }
    //            else if (choice == 3) {
    //                std::cout << "You will wake up again, won't you?\n\n";
    //                intro(status);
    //                break;
    //            }
    //        }
    //    }
    //}

    //return 0;
}