#include <iostream>
#include <limits> // for numeric_limits
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
        cout << "4. Generate Orders\n";
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
                // Process Repair
            {
                string partID;
                int quantityUsed;
                cout << "--- Process Repair ---" << endl;

                cout << "Enter 'done' for Part ID to finish entering parts." << endl;

                while (true) {
                    cout << "Enter Part ID: ";
                    cin >> partID;
                    if (partID == "done") {
                        break;
                    }
                    cout << "Enter Quantity Used: ";
                    cin >> quantityUsed;
                    cin.ignore();

                    garage.updateStock(partID, quantityUsed); // Update stock for each part used
                }
            }
            break;
            case 4:
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