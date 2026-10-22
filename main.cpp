#include <iostream>
#include <string>
#include "maintenance.h"
#include "graph.h"

using namespace std;

int main() {
    Maintenance maintenance;
    HotelGraph hotel;

    // First floor.
    hotel.addLocation("Lobby");
    hotel.addLocation("Maintenance Office");
    hotel.addLocation("Hallway 1");
    hotel.addLocation("Room 101");
    hotel.addLocation("Room 102");
    hotel.addLocation("Room 103");
    hotel.addLocation("Stairs 1");
    hotel.addLocation("Elevator 1");

    // Second floor.
    hotel.addLocation("Hallway 2");
    hotel.addLocation("Room 201");
    hotel.addLocation("Room 202");
    hotel.addLocation("Room 203");
    hotel.addLocation("Stairs 2");
    hotel.addLocation("Elevator 2");

    // Connect the first-floor locations.
    hotel.addConnection("Lobby", "Maintenance Office");
    hotel.addConnection("Lobby", "Hallway 1");
    hotel.addConnection("Hallway 1", "Room 101");
    hotel.addConnection("Hallway 1", "Room 102");
    hotel.addConnection("Hallway 1", "Room 103");
    hotel.addConnection("Hallway 1", "Stairs 1");
    hotel.addConnection("Hallway 1", "Elevator 1");

    // Connect the second-floor locations.
    hotel.addConnection("Hallway 2", "Room 201");
    hotel.addConnection("Hallway 2", "Room 202");
    hotel.addConnection("Hallway 2", "Room 203");
    hotel.addConnection("Hallway 2", "Stairs 2");
    hotel.addConnection("Hallway 2", "Elevator 2");

    // Two ways to travel between floors.
    hotel.addConnection("Stairs 1", "Stairs 2");
    hotel.addConnection("Elevator 1", "Elevator 2");

    int choice;
    string leftover;

    while (true) {
        cout << endl;
        cout << "1. Add a maintenance request" << endl;
        cout << "2. View the next request" << endl;
        cout << "3. Complete the next request" << endl;
        cout << "4. Show hotel locations" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            getline(cin, leftover);
            cout << "Enter a number from 1 to 5." << endl;
            continue;
        }

        // Discard the rest of the menu input line.
        getline(cin, leftover);

        if (choice == 1) {
            string location;
            string problem;
            int urgency;

            cout << "Location: ";
            if (!getline(cin, location)) break;
            cout << "Problem: ";
            if (!getline(cin, problem)) break;
            cout << "Urgency (1 = high, 2 = medium, 3 = low): ";

            if (!(cin >> urgency)) {
                if (cin.eof()) break;
                cin.clear();
                getline(cin, leftover);
                cout << "Enter a number for urgency." << endl;
                continue;
            }

            getline(cin, leftover);
            maintenance.addRequest(location, problem, urgency);
        } else if (choice == 2) {
            maintenance.showNext();
        } else if (choice == 3) {
            maintenance.completeNext();
        } else if (choice == 4) {
            hotel.showLocations();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}
