#ifndef GARAGEMANAGER_H
#define GARAGEMANAGER_H
#include <iostream>
#include <vector>
#include <string>
#include "Part.h"

class GarageManager {
private:
    //Vector to store Part objects
    std::vector<Part> stock;

public:
    //Add a part to stock
    void addPart();

    //search for a part
    void searchPart();

    // Update stock quantity
    void updateStock(std::string partID, int quantityUsed);

    // Generate orders report
    void generateOrders();

    // Process a repair
    void processRepair();

    // Process delivery
    void processDelivery();

    // function to find a part by ID
    int findPartIndex(std::string partID) const;

    // function to find parts by name
    std::vector<int> findPartIndicesByName(std::string partName) const;
};
#endif