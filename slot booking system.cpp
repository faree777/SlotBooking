#include <iostream>
#include <string>
#include <array>

using namespace std;

// These are the  constants for slot availability
const int AVAILABLE = 0;
const int BOOKED = 1;

//These are  number of rooms and slots per room
const int Num Rooms = 3; // Change the number of rooms to 3
const int Num Slots = 2; // Change the number of slots to 2

// Used 2D array to store slot availability for each room and slot
array<array<int, Num Slots>, Num Rooms> slotAvailability = { AVAILABLE };

// Function is used to display available slots for a room
void displayAvailableSlots(int roomNumber) {
    cout << "Available Slots for Room " << roomNumber << ":\n";
    for (int slotNumber = 0; slotNumber < Num Slots; ++slotNumber) {
        if (slotAvailability[roomNumber - 1][slotNumber] == AVAILABLE) {
            cout << "Slot " << slotNumber + 1 << " (" << (slotNumber * 2 + 4) << "pm-" << (slotNumber * 2 + 6) << "pm)\n";
        }
    }
}

// Function is used  to book a slot for a room
void bookSlot(int roomNumber, int slotNumber, const string& teacherName, const string& subject, int numStudents) {
    if (roomNumber < 1 || roomNumber > Num Rooms || slotNumber < 1 || slotNumber > Num Slots) {
        cout << "Invalid room or slot number.\n";
        return;
    }

    int& slot = slotAvailability[roomNumber - 1][slotNumber - 1];

    if (slot == AVAILABLE) {
        slot = BOOKED;
        cout << "Slot booked successfully.\n";
        cout << "Teacher: " << teacherName << "\n";
        cout << "Subject: " << subject << "\n";
        cout << "Number of Students: " << numStudents << "\n";
    }
    else {
        cout << "Slot is already booked.\n";
    }
}

int main() {
    while (true) {
        cout << "Enter room number (1, 2, 3) to book a slot (or any other key to exit): ";
        int roomChoice;
        cin >> roomChoice;

        if (roomChoice < 1 || roomChoice > Num Rooms) {
            break;
        }

        displayAvailableSlots(roomChoice);

        cout << "Enter slot number (1 or 2) to book: ";
        int slotChoice;
        cin >> slotChoice;

        cout << "Enter teacher's name: ";
        string teacherName;
        cin.ignore(); //used to clear newline character from previous input
        getline(cin, teacherName);

        cout << "Enter subject: ";
        string subject;
        getline(cin, subject);

        cout << "Enter number of students: ";
        int numStudents;
        cin >> numStudents;

        bookSlot(roomChoice, slotChoice, teacherName, subject, numStudents);
    }

    return 0;
}
