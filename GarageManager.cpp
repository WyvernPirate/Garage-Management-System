#include "GarageManager.h"
#include <string>
#include <vector> 
#include <iomanip> 
#include <sstream> 
#include <iostream>
#include <limits>
#include <fstream>
#include <algorithm> 
using namespace std;

struct Order {
    std::string partName;
    int quantityOrdered;
    std::string partID;
};
// Function to clear the input buffer
void clearCin() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//method to add a new Part
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
    clearCin();
    
    cout << "Enter Unit Price: ";
    cin >> price;
    clearCin();
    
    Part newPart(id, name, quantity, price);
    stock.push_back(newPart);
    cout << "Part added successfully!" << endl;
}

//method to search for a part
void GarageManager::searchPart() {
    cout << "Search by (1) ID or (2) Name? ";
    int choice;
    cin >> choice;
    cin.ignore(); 

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

// Method to update stock
void GarageManager::updateStock(string partID, int quantityUsed) {
    int index = findPartIndex(partID);
    if (index != -1) {
        int currentQuantity = stock[index].getQuantity();
        if (currentQuantity >= quantityUsed) {
            stock[index].setQuantity(currentQuantity - quantityUsed);
            cout << "Stock updated. " << quantityUsed << " "
                 << "removed from " << stock[index].getName() << endl;
        } else {
            cout << "Error: Not enough " << stock[index].getName()
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
        return; 
    }

    cout << "Parts that need to be ordered (and saved to orders.txt):" << endl;
    for (const Part& part : stock) {
        if (part.getQuantity() < 10) { //Reorder if quantity is less than 10
            cout << "Part ID: " << part.getID() << ", Part Name: " << part.getName()
                 << ", Quantity in Stock: " << part.getQuantity() << endl;

            // Save the order to the file
            ordersFile << part.getID() << "," << part.getName() << ","
                        << part.getQuantity() << endl;
        }
    }
    ordersFile.close(); // Close the file
}

void GarageManager::processRepair() {
    cout << "--- Process Repair ---" << endl;

    vector<pair<string, int>> partsUsed; // Store part IDs and quantities used
    string partID;
    int quantityUsed;
    double totalCost = 0.0;
    bool validRepair = true;
    string invoiceFileName;

    cout << "Enter 'done' for Part ID to finish entering parts." << endl;

    while (true) {
        cout << "Enter Part ID: ";
        cin >> partID;
        cin.ignore();

        if (partID == "done") {
            break;
        }

        cout << "Enter Quantity Used: ";
        cin >> quantityUsed;
        cin.ignore();

        partsUsed.push_back(make_pair(partID, quantityUsed));
    }

    // Validate parts and update stock
    for (const auto& part : partsUsed) {
        int index = findPartIndex(part.first); // Find part index
        if (index == -1) {
            cout << "Error: Part with ID " << part.first << " not found." << endl;
            validRepair = false;
        } else if (stock[index].getQuantity() < part.second) {
            cout << "Error: Not enough " << stock[index].getName()
                 << " in stock. Only " << stock[index].getQuantity()
                 << " available." << endl;
            validRepair = false;
        }
    }

    // Generate invoice and update stock if repair is valid
    if (validRepair) {
        cout << "Enter the invoice filename (invoice.txt): ";
        cin >> invoiceFileName;

        ofstream invoiceFile(invoiceFileName); // Open file to write the invoice

        if (!invoiceFile.is_open()) {
            cerr << "Error: Could not open invoice file!" << endl;
            return; 
        }

        invoiceFile << "--- Invoice ---" << endl; 
        invoiceFile << "-----------------------------------------" << endl;
        invoiceFile << left << setw(10) << "Quantity" << left << setw(20) << "Part Name"
                    << right << setw(10) << "Cost" << endl;
        invoiceFile << "-----------------------------------------" << endl;

        for (const auto& part : partsUsed) {
            int index = findPartIndex(part.first);
            double partCost = stock[index].getPrice() * part.second;
            totalCost += partCost; // Calculate total cost

            invoiceFile << left << setw(10) << part.second
                        << left << setw(20) << stock[index].getName()
                        << right << setw(10) << fixed << setprecision(2) << partCost << endl;
            updateStock(part.first, part.second); // Update stock
        }

        invoiceFile << "-----------------------------------------" << endl;
        invoiceFile << right << setw(30) << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;

        invoiceFile.close(); // Close the invoice file

        cout << "Invoice generated and saved to " << invoiceFileName << endl;
    } else {
        cout << "Repair cannot be processed due to errors." << endl;
    }
}
void GarageManager::processDelivery() {
    cout << "--- Process Delivery ---" << endl;

    vector<pair<string, int>> deliveredParts; // Store delivered part IDs and quantities
    string partID;
    int quantityDelivered;
    bool validDelivery = true;
    vector<Order> orders; 
    cout << "Enter delivered parts (Enter 'done' for Part ID to finish):" << endl;

    while (true) {
        cout << "Enter Part ID: ";
        cin >> partID;
        if (partID == "done") {
            break;
        }
        cout << "Enter Quantity Delivered: ";
        cin >> quantityDelivered;
        cin.ignore();

        deliveredParts.push_back(make_pair(partID, quantityDelivered));
    }

    // Read Orders from File
    ifstream ordersFileIn("orders.txt");
    if (!ordersFileIn.is_open()) {
        cerr << "Error: Could not open orders.txt for reading!" << endl;
        return;
    }

    string line;
    while (getline(ordersFileIn, line)) {
        Order order;
        stringstream ss(line);
        getline(ss, order.partID, ',');
        getline(ss, order.partName, ',');
        ss >> order.quantityOrdered;
        orders.push_back(order);
    }
    ordersFileIn.close();

    //Validate Delivered Parts Against Orders
    for (const auto& deliveredPart : deliveredParts) {
        bool found = false;
        for (const auto& order : orders) {
            if (deliveredPart.first == order.partID) {
                found = true;
                if (deliveredPart.second > order.quantityOrdered) {
                    cout << "Error: Delivered quantity for Part ID " << deliveredPart.first
                         << " exceeds the quantity ordered." << endl;
                    validDelivery = false;
                }
                break; 
            }
        }
        if (!found) {
            cout << "Error: Part with ID " << deliveredPart.first << " was not ordered." << endl;
            validDelivery = false;
        }
    }

    // Update Stock and Remove Orders
    if (validDelivery) {
        cout << "\n--- Delivery Report ---" << endl;
        for (const auto& deliveredPart : deliveredParts) {
            int index = findPartIndex(deliveredPart.first);
            if (index != -1) {
                int currentQuantity = stock[index].getQuantity();
                stock[index].setQuantity(currentQuantity + deliveredPart.second);
                cout << "Updated stock for Part ID: " << deliveredPart.first
                     << ", Added: " << deliveredPart.second << endl;
            } else {
                cout << "Error: Part with ID " << deliveredPart.first << " was not found in stock." << endl;
                validDelivery = false;
            }
        }
        if (validDelivery) {
            //Remove Delivered Orders 
            orders.erase(remove_if(orders.begin(), orders.end(),
                                  [&](const Order& order) {
                                      for (const auto& deliveredPart : deliveredParts) {
                                          if (order.partID == deliveredPart.first) {
                                              return true;
                                          }
                                      }
                                      return false; 
                                  }),
                        orders.end());

            //Write Remaining Orders Back to File
            ofstream ordersFileOut("orders.txt");
            if (!ordersFileOut.is_open()) {
                cerr << "Error: Could not open orders.txt for writing!" << endl;
                return;
            }
            for (const auto& order : orders) {
                ordersFileOut << order.partID << "," << order.partName << ","
                            << order.quantityOrdered << endl;
            }
            ordersFileOut.close();

            cout << "Delivery processed successfully, and orders.txt updated." << endl;
        } else {
            cout << "Delivery processing encountered errors." << endl;
        }

    } else {
        cout << "Error: Invalid delivery. Some parts were not ordered or quantity exceeded." << endl;
    }
}

int GarageManager::findPartIndex(string partID) const {
    for (size_t i = 0; i < stock.size(); ++i) {
        if (stock[i].getID() == partID) {
            return static_cast<int>(i);
        }
    }
    return -1; // Part not found
}

std::vector<int> GarageManager::findPartIndicesByName(std::string partName) const {
    std::vector<int> indices;
    for (size_t i = 0; i < stock.size(); ++i) {
        if (stock[i].getName() == partName) {
            indices.push_back(static_cast<int>(i));
        }
    }
    return indices;
}