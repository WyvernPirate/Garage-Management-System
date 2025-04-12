#include <iostream>
#include <limits> 
#include "GarageManager.cpp"

using namespace std;

int main() {
    GarageManager garage;

    int choice;
    do {
        cout << "\nGarage Repair Management System\n";
        cout << "1. Add Part\n";
        cout << "2. Search Part\n";
        cout << "3. Process Repair\n";
        cout << "4. Process Delivery\n"; 
        cout << "5. Generate Orders\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                garage.addPart();
                break;
            case 2:
                garage.searchPart();
                break;
            case 3:
                garage.processRepair();
                break;
            case 4:
                garage.processDelivery(); 
                break;
            case 5:
                garage.generateOrders();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}