#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    int choice, days;
    string bookTitle, returnDate, issueDate;
    cout << "Library Management System" << endl;
    cout << "1. Borrow a book" << endl;
    cout << "2. Return a book" << endl;
    cout << "Select any Option: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1) {

        cout << "Enter the title of book: ";
        getline(cin, bookTitle);
        cout << "Enter the number of days you want to borrow the book? : ";
        cin >> days;
        cout << "Book Issued for " << days << " days. Thank you! ";

    }
    else if (choice == 2) {
        cout << "Enter number of days you were issued the book: ";
        cin >> days;
        cout << "Book issue date (YYYY-MM-DD) : ";
        cin >> issueDate;
        cout << "Book Return date (YYYY-MM-DD) : ";
        cin >> returnDate;

        tm t1 = {};
        tm t2 = {};

        istringstream issueDateStream(issueDate);
        issueDateStream >> get_time(&t1, "%Y-%m-%d");

        istringstream returnDateStream(returnDate);
        returnDateStream >> get_time(&t2, "%Y-%m-%d");

        chrono::system_clock::time_point issueTime = chrono::system_clock::from_time_t(mktime(&t1));
        chrono::system_clock::time_point returnTime = chrono::system_clock::from_time_t(mktime(&t2));

        chrono::duration<int> difference = chrono::duration_cast<chrono::hours>(returnTime - issueTime);
        int daysDifference = abs(difference.count()) / 24;

        if (daysDifference > days) {
            cout << "You were unable to return the book on time. You are charged $" << daysDifference;
        }
    }
    return 0;
}