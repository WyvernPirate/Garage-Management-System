#include "GarageManager.h"
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

// Function to clear the input buffer
void clearCin() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//function to add a new Part
void GarageManager::addPart() {
    string id, name;
    int quantity;
    double price;

    cout << "Enter Part ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Part Name: ";
    getline(cin, name);

    cout << "Enter Quantity in Stock: ";
    cin >> quantity;

    cout << "Enter Unit Price: ";
    cin >> price;

    Part newPart(id, name, quantity, price);
    stock.push_back(newPart);

    cout << "Part added successfully!" << endl;
}
 
//function to search for a part
void GarageManager::searchPart() {
    cout << "Search by (1) ID or (2) Name? ";
    int choice;
    cin >> choice;
    cin.ignore(); // Consume the newline character

    //search by ID
    if (choice == 1) {
        string searchID;
        cout << "Enter Part ID to search: ";
        cin >> searchID;
        int index = findPartIndex(searchID);
        if (index != -1) {
            cout << "Part found:" << endl;
            stock[index].displayPartDetails();
        } else {
            cout << "Part with ID " << searchID << " not found." << endl;
        }
    
    //search by name     
    } else if (choice == 2) {
        string searchName;
        cout << "Enter Part Name to search: ";
        getline(cin, searchName);
        vector<int> indices = findPartIndicesByName(searchName);
        if (!indices.empty()) {
            cout << "Parts found:" << endl;
            for (int index : indices) {
                stock[index].displayPartDetails();
                cout << endl;
            }
        } else {
            cout << "No parts found with name " << searchName << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }
}

// function to update stock by ID
void GarageManager::updateStock(string partID, int quantityUsed) {
    int index = findPartIndex(partID);
    if (index != -1) {
        int currentQuantity = stock[index].getQuantityInStock();
        if (currentQuantity >= quantityUsed) {
            stock[index].setQuantityInStock(currentQuantity - quantityUsed);
            cout << "Stock updated. " << quantityUsed << " "
                 << "removed from " << stock[index].getPartName() << endl;
        } else {
            cout << "Error: Not enough " << stock[index].getPartName()
                 << " in stock. Only " << currentQuantity << " available." << endl;
        }
    } else {
        cout << "Part with ID " << partID << " not found." << endl;
    }
}

void GarageManager::generateOrders() {
    ofstream ordersFile("orders.txt", ios::app); // Open the orders file

    if (!ordersFile.is_open()) {
        cerr << "Error: Could not open orders file!" << endl;
        return; // Exit the function if the file cannot be opened
    }

    cout << "Parts that need to be ordered (and saved to orders.txt):" << endl;
    for (const Part& part : stock) {
        if (part.getQuantityInStock() < 10) { //Reorder if quantity is less than 10
            cout << "Part ID: " << part.getPartID() << ", Part Name: " << part.getPartName()
                 << ", Quantity in Stock: " << part.getQuantityInStock() << endl;

            // Save the order to the file
            ordersFile << part.getPartID() << "," << part.getPartName() << ","
                       << part.getQuantityInStock() << endl;
        }
    }
    ordersFile.close(); // Close the file
}

int GarageManager::findPartIndex(string partID) const {
    for (size_t i = 0; i < stock.size(); ++i) {
        if (stock[i].getPartID() == partID) {
            return static_cast<int>(i);
        }
    }
    return -1; // Part not found
}

std::vector<int> GarageManager::findPartIndicesByName(std::string partName) const {
    std::vector<int> indices;
    for (size_t i = 0; i < stock.size(); ++i) {
        if (stock[i].getPartName() == partName) {
            indices.push_back(static_cast<int>(i));
        }
    }
    return indices;
}