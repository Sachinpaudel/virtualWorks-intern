#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Hotel {
private:
    int roomNumber;
    string customerName;
    string phoneNumber;
    int days;
    float roomPrice;

public:

    void bookRoom() {
        cout << "\n Enter Room Number: ";
        cin >> roomNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Phone Number: ";
        getline(cin, phoneNumber);

        cout << "Enter Number of Days: ";
        cin >> days;

        cout << "Enter Price Per Day: ";
        cin >> roomPrice;

        saveToFile();

        cout << "\nRoom booked successfully!\n";
    }


    void saveToFile() {
        ofstream file("hotel.txt", ios::app);

        file << roomNumber << endl;
        file << customerName << endl;
        file << phoneNumber << endl;
        file << days << endl;
        file << roomPrice << endl;

        file.close();
    }


    void viewBookings() {
        ifstream file("hotel.txt");

        if (!file) {
            cout << "\nNo booking records found.\n";
            return;
        }

        cout << "\n===== HOTEL BOOKINGS =====\n";

        while (file >> roomNumber) {

            file.ignore();

            getline(file, customerName);
            getline(file, phoneNumber);

            file >> days;
            file >> roomPrice;

            cout << "\nRoom Number: " << roomNumber;
            cout << "\nCustomer Name: " << customerName;
            cout << "\nPhone Number: " << phoneNumber;
            cout << "\nDays: " << days;
            cout << "\nPrice Per Day: Rs. " << roomPrice;
            cout << "\nTotal Bill: Rs. " << days * roomPrice;
            cout << "\n-------------------------\n";
        }

        file.close();
    }


    void searchCustomer() {
        int searchRoom;
        bool found = false;

        cout << "\nEnter Room Number: ";
        cin >> searchRoom;

        ifstream file("hotel.txt");

        while (file >> roomNumber) {

            file.ignore();

            getline(file, customerName);
            getline(file, phoneNumber);

            file >> days;
            file >> roomPrice;

            if (roomNumber == searchRoom) {

                cout << "\nBooking Found!\n";

                cout << "Room Number: " << roomNumber << endl;
                cout << "Customer Name: " << customerName << endl;
                cout << "Phone Number: " << phoneNumber << endl;
                cout << "Days: " << days << endl;
                cout << "Price Per Day: Rs. " << roomPrice << endl;

                found = true;
                break;
            }
        }

        file.close();

        if (!found) {
            cout << "\nRoom booking not found.\n";
        }
    }


    void checkout() {
        int checkoutRoom;
        bool found = false;

        cout << "\nEnter Room Number for Checkout: ";
        cin >> checkoutRoom;

        ifstream file("hotel.txt");
        ofstream temp("temp.txt");

        while (file >> roomNumber) {

            file.ignore();

            getline(file, customerName);
            getline(file, phoneNumber);

            file >> days;
            file >> roomPrice;

            if (roomNumber == checkoutRoom) {

                float totalBill = days * roomPrice;

                cout << "\n===== BILL =====\n";
                cout << "Customer: " << customerName << endl;
                cout << "Room Number: " << roomNumber << endl;
                cout << "Days Stayed: " << days << endl;
                cout << "Price Per Day: Rs. " << roomPrice << endl;
                cout << "Total Bill: Rs. " << totalBill << endl;

                found = true;
            }

            else {

                temp << roomNumber << endl;
                temp << customerName << endl;
                temp << phoneNumber << endl;
                temp << days << endl;
                temp << roomPrice << endl;
            }
        }

        file.close();
        temp.close();

        remove("hotel.txt");
        rename("temp.txt", "hotel.txt");

        if (found) {
            cout << "\nCheckout successful!\n";
        }

        else {
            cout << "\nRoom not found.\n";
        }
    }
};


int main() {

    Hotel hotel;

    int choice;

    do {

        cout << "\n==============================";
        cout << "\n   HOTEL MANAGEMENT SYSTEM";
        cout << "\n==============================";

        cout << "\n1. Book Room";
        cout << "\n2. View All Bookings";
        cout << "\n3. Search Booking";
        cout << "\n4. Checkout";
        cout << "\n5. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;


        switch (choice) {

        case 1:
            hotel.bookRoom();
            break;

        case 2:
            hotel.viewBookings();
            break;

        case 3:
            hotel.searchCustomer();
            break;

        case 4:
            hotel.checkout();
            break;

        case 5:
            cout << "\nThank you for using Hotel Management System!\n";
            break;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}