# Car Repair Garage Management System

## Overview

This C++ application is a Car Repair Garage Management System designed to manage car repairs, track parts inventory, handle orders, generate invoices, and process deliveries. The system utilizes object-oriented programming (OOP) principles for a modular, maintainable, and efficient design.

## Features

* **Part Management:**
    * Stores part details (ID, name, quantity, price).
    * Provides methods to access and update part information.
* **Stock and Order Management:**
    * Manages part inventory.
    * Allows adding new parts to stock.
    * Enables searching for parts by ID or name.
    * Updates stock quantities.
    * Generates reports for parts that need reordering.
    * Saves orders to a file (`orders.txt`).
* **Repair and Invoice System:**
    * Processes car repairs by entering parts used.
    * Validates entered parts against stock.
    * Calculates the total repair cost.
    * Generates invoices and saves them to files.
* **Delivery Handling:**
    * Processes deliveries of new parts.
    * Validates delivered parts against orders in `orders.txt`.
    * Updates stock quantities based on deliveries.
    * Removes delivered orders from `orders.txt`.

## Program Structure

The system is organized into the following classes and files:

* `Part` Class (`Part.h`, `Part.cpp`): Represents a part in the garage's inventory.
* `GarageManager` Class (`GarageManager.h`, `GarageManager.cpp`): Manages part inventory, orders, repairs, and deliveries.
* `Main Program` (`main.cpp`): Provides a user interface to interact with the system.

## Usage

1.  **Compilation:**

    * Ensure you have a C++ compiler (e.g., g++).
    * Compile the source files:

        \`\`\`bash
        g++ Part.cpp GarageManager.cpp main.cpp -o garage_system
        \`\`\`
2.  **Execution:**

    * Run the compiled executable:

        \`\`\`bash
        ./garage_system
        \`\`\`
3.  **Interaction:**

    * The program will display a menu with the following options:

        1.  Add Part
        2.  Search Part
        3.  Process Repair
        4.  Process Delivery
        5.  Generate Orders
        0.  Exit
    * Enter the number corresponding to the desired operation.
    * Follow the prompts to enter the required information.

## Input/Output Files

The system uses the following files:

* `orders.txt`: Stores details of parts that have been ordered. The system reads from and writes to this file when processing deliveries and generating orders.
* `invoice.txt`: The system will prompt for a filename and write the invoice details to the specified file.
