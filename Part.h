#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>

class Part {
private:
    std::string partID;
    std::string partName;
    int quantityInStock;
    double unitPrice;

public:
    // Constructor
    Part(std::string id, std::string name, int quantity, double price)
        : partID(id), partName(name), quantityInStock(quantity), unitPrice(price) {}

    // Getter method
    std::string getPartID() const { return partID; }
    std::string getPartName() const { return partName; }
    int getQuantityInStock() const { return quantityInStock; }
    double getUnitPrice() const { return unitPrice; }

    // Setter methods
    void setPartName(std::string name) { partName = name; }
    void setQuantityInStock(int quantity) { quantityInStock = quantity; }
    void setUnitPrice(double price) { unitPrice = price; }

    // Method to display part details
    void displayPartDetails() const {
        std::cout << "Part ID: " << partID << std::endl;
        std::cout << "Part Name: " << partName << std::endl;
        std::cout << "Quantity in Stock: " << quantityInStock << std::endl;
        std::cout << "Unit Price: " << unitPrice << std::endl;
    }
};

#endif