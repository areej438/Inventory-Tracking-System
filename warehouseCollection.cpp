#include <iostream>
#include "validation.h"
#include <sstream>
#include <fstream>
#include "warehouseCollection.h"
#include "colors.h"
using namespace std;

// constructor
warehouseCollection::warehouseCollection() {
    count = 0;
}

// ADD
void warehouseCollection::addWarehouse() {
    if (count >= 100) {
        cout << PASTEL_GREEN << "Storage is Full!!" << RESET << endl;
        return;
    }

    cout << PASTEL_YELLOW << BOLD;
    cout << "-------------------------------" << endl;
    cout << PASTEL_LAVENDER;
    cout << "      Enter All Information" << endl;
    cout << PASTEL_YELLOW;
    cout << "-------------------------------" << RESET << endl << endl;

    int id;
    id = intValidation("Enter Warehouse ID: ");
    if (returnIndexOfWarehouseId(id) != -1) {
        cout << PASTEL_RED << "This Warehouse ID already exist!!" << RESET << endl;
        return;
    }
    warehouses[count].setWarehouseID(id);

    int staffID;
    staffID = intValidation("Enter Staff ID: ");
    warehouses[count].setStaffID(staffID);

    string name;
    cout << PASTEL_BROWN << "Enter Warehouse Name: ";
    cout << PASTEL_BEIGE;
    cin.ignore();
    getline(cin, name);
    cout << RESET;
    warehouses[count].setWarehouseName(name);

    string location;
    cout << PASTEL_BROWN << "Enter Warehouse Location: ";
    cout << PASTEL_BEIGE;
    getline(cin, location);
    cout << RESET;
    warehouses[count].setWarehouseLocation(location);

    int capacity;
    capacity = intValidation("Enter Warehouse Capacity: ");
    warehouses[count].setWarehouseCapacity(capacity);

    count++;
}

// DISPLAY ALL
void warehouseCollection::displayWarehouse() {
    if (count == 0) {
        cout << PASTEL_RED << "NO Warehouse is Entered yet!!" << RESET << endl;
        return;
    }

    cout << PASTEL_YELLOW << BOLD;
    cout << "-------------------------------" << endl;
    cout << PASTEL_LAVENDER;
    cout << "  Your Entered Warehouse Details " << endl;
    cout << PASTEL_YELLOW;
    cout << "-------------------------------" << RESET << endl << endl;

    for (int i = 0; i < count; i++) {
        cout << PASTEL_BROWN << "Warehouse ID      : " << PASTEL_BEIGE << warehouses[i].getWarehouseID() << RESET << endl;
        cout << PASTEL_BROWN << "Staff ID          : " << PASTEL_BEIGE << warehouses[i].getStaffID() << RESET << endl;
        cout << PASTEL_BROWN << "Warehouse Name    : " << PASTEL_BEIGE << warehouses[i].getWarehouseName() << RESET << endl;
        cout << PASTEL_BROWN << "Warehouse Location: " << PASTEL_BEIGE << warehouses[i].getWarehouseLocation() << RESET << endl;
        cout << PASTEL_BROWN << "Warehouse Capacity: " << PASTEL_BEIGE << warehouses[i].getWarehouseCapacity() << RESET << endl;
        cout << PASTEL_BEIGE << "-------------------------------------" << endl;
    }
}

// FIND
void warehouseCollection::findWarehouseByID() {
    if (count == 0) {
        cout << PASTEL_RED << "NO Warehouse is Entered Yet!!" << endl;
        return;
    }

    int searchID;
     searchID = intValidation("Enter Warehouse ID: ");

    bool warehouseFound = false;

    for (int i = 0; i < count; i++) {
        if (searchID == warehouses[i].getWarehouseID()) {
           warehouseFound = true;

            cout << PASTEL_YELLOW << BOLD;
            cout << "-------------------------------" << endl;
            cout << PASTEL_LAVENDER;
            cout << "  Your Searched Warehouse Details " << endl;
            cout << PASTEL_YELLOW;
            cout << "-------------------------------" << RESET << endl << endl;

            cout << PASTEL_BROWN << "Warehouse ID      : " << PASTEL_BEIGE << warehouses[i].getWarehouseID() << endl;
            cout << PASTEL_BROWN << "Staff ID          : " << PASTEL_BEIGE << warehouses[i].getStaffID() << endl;
            cout << PASTEL_BROWN << "Warehouse Name    : " << PASTEL_BEIGE << warehouses[i].getWarehouseName() << endl;
            cout << PASTEL_BROWN << "Warehouse Location: " << PASTEL_BEIGE << warehouses[i].getWarehouseLocation() << endl;
            cout << PASTEL_BROWN << "Warehouse Capacity: " << PASTEL_BEIGE << warehouses[i].getWarehouseCapacity() << endl;
            cout << PASTEL_BEIGE << "----------------------" << endl;

            break;
        }
    }

    if (!warehouseFound) {
        cout << PASTEL_RED << "This Warehouse ID does not exist!!" << RESET << endl;
    }
}

// HELPER
int warehouseCollection::returnIndexOfWarehouseId(int id) {
    for (int i = 0; i < count; i++) {
        if (id == warehouses[i].getWarehouseID()) {
            return i;
        }
    }
    return -1;
}

// UPDATE
void warehouseCollection::updateWarehouse() {
    if (count == 0) {
        cout << PASTEL_RED << "NO Warehouse is Entered yet!!" << RESET << endl;
        return;
    }

    int id;
    id = intValidation("Enter Warehouse ID you want to update: ");
    int index = returnIndexOfWarehouseId(id);

    if (index == -1) {
        cout << PASTEL_RED << "Warehouse ID does not exist!!" << endl;
        return;
    }

    int newID;
    newID = intValidation("Enter new Warehouse ID: ");
    warehouses[index].setWarehouseID(newID);

    int staffID;
    staffID = intValidation("Enter new Staff ID: ");
    warehouses[index].setStaffID(staffID);
    

    string name;
    cout << PASTEL_BROWN << "Enter new Warehouse Name: ";
    cout << PASTEL_BEIGE;
    cin.ignore();
    getline(cin, name);
    warehouses[index].setWarehouseName(name);
    cout << RESET;

    string location;
    cout << PASTEL_BROWN << "Enter new Warehouse Location: ";
    cout << PASTEL_BEIGE;
    getline(cin, location);
    warehouses[index].setWarehouseLocation(location);
    cout << RESET;

    int capacity;
    capacity = intValidation("Enter new Warehouse Capacity: ");
    warehouses[index].setWarehouseCapacity(capacity);

    cout << PASTEL_GREEN << "Warehouse updated successfully!" << endl;
}

// REMOVE
void warehouseCollection::removeWarehouse() {
    if (count == 0) {
        cout << PASTEL_RED << "NO Warehouse is Entered yet!!" << RESET << endl;
        return;
    }

    int id;
    id = intValidation("Enter Warehouse ID you want to remove: ");
    int index = returnIndexOfWarehouseId(id);

    if (index == -1) {
        cout << PASTEL_RED << "Warehouse ID does not exist!!" << endl;
        return;
    }

    for (int i = index; i < count - 1; i++) {
        warehouses[i] = warehouses[i + 1];
    }

    count--;

    cout << PASTEL_GREEN << "Warehouse removed successfully!" << endl;
}

//function for file reading
void warehouseCollection::loadFromCSV() {//sir uses parameter here bcz if you have more than one file 
    count = 0;//this count is added on chatgpt suggestion why?   //then you can add any filename insted hard coding but we have only 2 simple files
    ifstream rfile("warehouse.csv"); //same file name check why?
    if (!rfile) {
        cout << "File is not open " << endl;
        return;
    }
    string line;
    getline(rfile, line);
    while (getline(rfile, line)) {
        stringstream ss(line);
        string Widstr;
        getline(ss, Widstr, ',');
        int Wid = stoi(Widstr);
        string Sidstr;
        getline(ss, Sidstr, ',');
        int Sid = stoi(Sidstr);
        string name;
        getline(ss, name, ',');
        string loc;
        getline(ss, loc, ',');
        string capacity;
        getline(ss, capacity, ',');
        int cpcty= stoi(capacity);
        //now assign values to suitable count
        warehouses[count].setWarehouseID(Wid);
        warehouses[count].setStaffID(Sid);
        warehouses[count].setWarehouseName(name);
        warehouses[count].setWarehouseLocation(loc);
        warehouses[count].setWarehouseCapacity(cpcty);


        count++;
    }
    rfile.close();
}

//write into file function
void warehouseCollection::saveToFile() {
    ofstream outFile("warehouse.csv");//csv is liyy qk is ny dobara load bhi to hona hy us k liyr usy comma separated values chaoye
    if (!outFile) {
        cout << "file is not opened" << endl;
        return;//chexk why 
    }
    outFile << "Warehouse ID,Staff ID,Warehouse Name,Warehouse Location,Warehouse Capacity" << endl;
    if (count == 0) {
        cout << PASTEL_RED << "NO Products are entered yet,Nothing to write in file!!" << endl;
        outFile.close();
        return;
    }
    for (int i = 0; i < count; i++) {
        outFile << warehouses[i].getWarehouseID() << "," << warehouses[i].getStaffID() << "," << warehouses[i].getWarehouseName()
            << "," << warehouses[i].getWarehouseLocation() << "," << warehouses[i].getWarehouseCapacity() << endl;
    }
    cout << PASTEL_GREEN << "Products detail are written succesfully" << endl;
    outFile.close();
}