#include "Part.h"
#include <iostream>
using namespace std;
// Constructor 
Part::Part(string id, string name, int quantity, double price)
    : partID(id), partName(name), quantityInStock(quantity), unitPrice(price) {}
//setter methods

void Part::setName(string name) {
    partName = name;
}
void Part::setQuantity(int quantity) {
    quantityInStock = quantity;
}
void Part::setPrice(double price) {
    unitPrice = price;
}

// getters 
string Part::getID() const {
    return partID;
}
string Part::getName() const {
    return partName;
}
int Part::getQuantity() const {
    return quantityInStock;
}
double Part::getPrice() const {
    return unitPrice;
}

// Method to display part details implementation
void Part::displayPartDetails() const {
    cout << "Part ID: " << partID << endl;
    cout << "Part Name: " << partName << endl;
    cout << "Quantity in Stock: " << quantityInStock << endl;
    cout << "Unit Price: " << unitPrice << endl;
}