#ifndef PART_H
#define PART_H
#include <iostream>
#include <string>
using namespace std;

class Part {
private:
    string partID;
    string partName;
    int quantityInStock;
    double unitPrice;
public:
    // Constructor
    Part(string id, string name, int quantity, double price)
        : partID(id), partName(name), quantityInStock(quantity), unitPrice(price) {}

    // Getter methods
    string getID() const { return partID; }
    string getName() const { return partName; }
    int getQuantity() const { return quantityInStock; }
    double getPrice() const { return unitPrice; }

    // Setter methods
    void setName(string name) { partName = name; }
    void setQuantity(int quantity) { quantityInStock = quantity; }
    void setPrice(double price) { unitPrice = price; }

    // Method to display part details
    void displayPartDetails() const {
        cout << "Part ID: " << partID << endl;
        cout << "Part Name: " << partName << endl;
        cout << "Quantity in Stock: " << quantityInStock << endl;
        cout << "Unit Price: " << unitPrice << endl;
    }
};
#endif