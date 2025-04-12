#include "Part.h"
#include <iostream>
using namespace std;
// Constructor 
Part::Part(string id, string name, int quantity, double price)
    : partID(id), partName(name), quantityInStock(quantity), unitPrice(price) {}

// getters 
string Part::getPartID() const {
    return partID;
}
string Part::getPartName() const {
    return partName;
}
int Part::getQuantityInStock() const {
    return quantityInStock;
}
double Part::getUnitPrice() const {
    return unitPrice;
}

//setters
void Part::setPartName(string name) {
    partName = name;
}
void Part::setQuantityInStock(int quantity) {
    quantityInStock = quantity;
}
void Part::setUnitPrice(double price) {
    unitPrice = price;
}

// Method to display part details implementation
void Part::displayPartDetails() const {
    cout << "Part ID: " << partID << endl;
    cout << "Part Name: " << partName << endl;
    cout << "Quantity in Stock: " << quantityInStock << endl;
    cout << "Unit Price: " << unitPrice << endl;
}