#pragma once
#include <string>
using namespace std;
class stockItem{
	int stockItemId;
	int productID;
	int stockQuantity;
	int purchaseID;
	int supplierID;
	string purchaseDate;
	string expiryDate;
	string stockStatus;
	string stockItemName;
public:

	//default constructor
	stockItem();

	//copy constructor 
	stockItem(const stockItem& obj); //you can chnage name of obj before submission

	//destructor
	~stockItem();

	//setter functions

	void setstockItemID(int SIid);
	void setProductID(int Pid);
	void setSupplierID(int Spid);
	void setStockQuantity(int Sq);
	void setPurchasingDate(string pDate);
	void setProductExpiryDate(string pExDate);
	void setstockStauts(string sStatus);
	void setPurchaseID(int Pid);
	void setStockItemName(string n);

	//getter functions

	int getStockItemID();
	int getProductID();
	int getSupplierID();
	int getStockQuantity();
	string getPurchasingDate();
	string getProductExpiryDate();
	string getStockStatus();
	string getStockItemName();
	int getPurchaseID();
};
