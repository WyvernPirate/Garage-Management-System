#ifndef GARAGEMANAGER_H
#define GARAGEMANAGER_H
#include <vector>
#include <string>
#include "Part.h"
#include <iostream>
using namespace std;

class GarageManager {
private:
    vector<Part> stock;
public:
    //Add a part to stock
    void addPart();

    //search for a part
    void searchPart();

    // Update stock quantity
    void updateStock(string partID, int quantityUsed);

    // Generate orders report
    void generateOrders();

    // Process a repair
    void processRepair();

    // Process delivery
    void processDelivery();

    // method to find a part by ID
    int findPartIndex(string partID) const;

    // method to find parts by name
    std::vector<int> findPartIndicesByName(string partName) const;
};
#endif

