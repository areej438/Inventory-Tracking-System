#pragma once
#include "warehouse.h"

class warehouseCollection {
    warehouse warehouses[100];
    int count;

public:
    // default constructor
    warehouseCollection();

    // functions 
    void addWarehouse();
    void displayWarehouse();
    void findWarehouseByID();
    void updateWarehouse();
    void removeWarehouse();
    // helper function
    int returnIndexOfWarehouseId(int id);
    //function for file handling
    void loadFromCSV();
    void saveToFile();
};
