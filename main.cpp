#include <iostream>
#include <string>

using namespace std;

// ANSI escape codes for colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"

// Structure to represent an Event
struct Event {
    int eventNumber;
    string eventName;
    string date;
    string location;
};

const int MAX_EVENTS = 100;

// Function to display all events
void displayEvents(Event events[], int count) {
    system("CLS");
    if (count == 0) {
        cout << RED << "No events found." << RESET <<endl;
        return;
    }
    cout << "Events List:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\t\t-------------------------" << RESET << endl;
        cout << "\t\tEvent Number: " << YELLOW << events[i].eventNumber << RESET << endl;
        cout  << "\t\tEvent Name: " << YELLOW << events[i].eventName << RESET << endl;
        cout  << "\t\tDate: " << YELLOW << events[i].date << RESET << endl;
        cout  << "\t\tLocation: " << YELLOW << events[i].location << RESET << endl;
        cout << "\t\t-------------------------" << endl;
    }
}

// Function to add a new event
void addEvent(Event events[], int &count) {
    int j;
    if (count < MAX_EVENTS) {
        Event newEvent;
        cout << "\t\tEnter Event Number: ";
        cin >> newEvent.eventNumber;
        for (int i = 0; i < count; i++) {
            if (events[i].eventNumber == newEvent.eventNumber) {
                cout << RED << "\t\tEvent number " << newEvent.eventNumber << " already exists. Please enter a unique number." << RESET << endl;
                addEvent(events, count);
                return;
            }
        }
        cin.ignore();
        cout << "\t\tEnter Event Name: ";
        getline(cin, newEvent.eventName);
        do {
            j = 0;
            cout << "\t\tEnter Date (mm/dd/yyyy): ";
            getline(cin, newEvent.date);
            for (int i = 0; i < count; i++) {
                if (events[i].date == newEvent.date) {
                    cout << RED << "\t\tEvent Date " << newEvent.date << " already exists. Please enter a unique Date." << RESET << endl;
                    j = 1;
                }
            }
        } while (j==1);
        cout << "\t\tEnter Location: ";
        getline(cin, newEvent.location);

        events[count] = newEvent;
        count++;
        cout << GREEN << "Event added successfully!" << RESET << endl;
    } else {
        cout << RED << "Event limit reached. Cannot add more events." << RESET << endl;
    }
}

// Function to update an existing event
void updateEvent(Event events[], int count) {
    int eventNumber, j;
    cout << "Enter the Event Number to update: ";
    cin >> eventNumber;

    for (int i = 0; i < count; i++) {
        system("CLS");
        cout << "Event you want to update:" << endl;
        cout << "\t\t-------------------------" << RESET << endl;
        cout << "\t\tEvent Number: " << YELLOW << events[i].eventNumber << RESET << endl;
        cout  << "\t\tEvent Name: " << YELLOW << events[i].eventName << RESET << endl;
        cout  << "\t\tDate: " << YELLOW << events[i].date << RESET << endl;
        cout  << "\t\tLocation: " << YELLOW << events[i].location << RESET << endl;
        cout << "\t\t-------------------------" << RESET << endl;

        if (events[i].eventNumber == eventNumber) {
            cout << "\t\tUpdating Event Number: " << events[i].eventNumber << endl;
            cout << "\t\tEnter New Event Name: ";
            cin.ignore();
            getline(cin, events[i].eventName);
            do {
                j = 0;
                cout << "\t\tEnter New Date (mm/dd/yyyy): ";
                getline(cin, events[i].date);

                for (int y = 0; y < count; y++) {
                    if (events[i].date == events[y].date && events[i].eventNumber != events[y].eventNumber) {
                        cout << RED << "\t\tEvent Date " << events[i].date << " already exists. Please enter a unique Date." << RESET << endl;
                        j = 1;
                        break;
                    }
                }
            } while (j == 1);
            cout << "\t\tEnter New Location: ";
            getline(cin, events[i].location);
            cout << GREEN << "Event updated successfully!" << RESET << endl;
            return;
        }
    }
    cout << RED << "Event with number " << eventNumber << " not found." << RESET << endl;
}

void deleteEvent(Event events[], int &count) {
    int eventNumber;
    cout << "Enter the Event Number to delete: ";
    cin >> eventNumber;

    for (int i = 0; i < count; i++) {
        if (events[i].eventNumber == eventNumber) {

            for (int j = i; j < count - 1; j++) {
                events[j] = events[j + 1];
            }
            count--;
            cout << GREEN << "Event deleted successfully!" << RESET << endl;
            return;
        }
    }
    cout << "Event with number " << eventNumber << " not found." << endl;
}

int main() {
    Event events[MAX_EVENTS];
    int eventCount = 0;
    int choice;

    cout << BOLD << YELLOW
        << "\t\t\t\t\t______________________________________________"
        << "\n\t\t\t\t\t| WELCOME TO GROUP 8 EVENT MANAGEMENT SYSTEM |\n"
        << "\t\t\t\t\t==============================================\n" << RESET;

    do {
        cout << "Event Management System" << endl;
        cout << "\t\t1. Add Event" << endl;
        cout << "\t\t2. Display Events" << endl;
        cout << "\t\t3. Update Event" << endl;
        cout << "\t\t4. Delete Event" << endl;
        cout << "\t\t5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                addEvent(events, eventCount);
                break;
            case 2:
                displayEvents(events, eventCount);
                break;
            case 3:
                updateEvent(events, eventCount);
                break;
            case 4:
                deleteEvent(events, eventCount);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        cout << endl;
    } while (choice != 5);

    return 0;
}
