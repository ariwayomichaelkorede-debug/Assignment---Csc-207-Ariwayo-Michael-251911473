// Assignment - COS 201/CSC 207 Lecture
// Program 1: Check if a number is Odd or Even
//
// The program asks the user for an integer and reports
// whether it is an odd number or an even number.
//
// After each result the user gets a menu:
//   1 - Check another number (the program keeps running)
//   2 - Exit (the program closes)

#include <iostream>
#include <limits>

using namespace std;

// Returns true if the number is even, false if it is odd
bool isEven(int number) {
    return number % 2 == 0;
}

// Reads a valid integer from the user, re-prompting on bad input
int readNumber() {
    int number;
    while (true) {
        cout << "Enter a number: ";
        if (cin >> number) {
            return number;
        }
        // Clear the error state and discard the bad input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a whole number." << endl;
    }
}

// Reads a valid menu choice (1 or 2) from the user
int readChoice() {
    int choice;
    while (true) {
        cout << "Enter a choice: ";
        if (cin >> choice && (choice == 1 || choice == 2)) {
            return choice;
        }
        // Clear the error state and discard the bad input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }
}

// Clears leftover characters (like the Enter key) from the input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Shows the result for the given number
void showResult(int number) {
    if (isEven(number)) {
        cout << number << " is an Even number." << endl;
    } else {
        cout << number << " is an Odd number." << endl;
    }
}

int main() {
    cout << "===== Odd or Even Checker =====" << endl;

    while (true) {
        cout << endl;
        int number = readNumber();
        clearInputBuffer();
        showResult(number);

        cout << endl;
        cout << "======== OPTIONS ========" << endl;
        cout << "1. Check another number" << endl;
        cout << "2. Exit" << endl;
        cout << "=========================" << endl;

        int choice = readChoice();
        clearInputBuffer();

        if (choice == 2) {
            cout << endl << "Thank you for using the Odd or Even Checker. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
