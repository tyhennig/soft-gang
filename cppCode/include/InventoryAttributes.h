#ifndef INVENTORYATTRIBUTES_H
#define INVENTORYATTRIBUTES_H
#include <iostream>

using namespace std;

class InventoryAttributes
{
public:
	InventoryAttributes();
	InventoryAttributes(int id, string att, int q, double p);
	~InventoryAttributes();
	int itemID;
	string attribute;
	int quantityAv;
	double price;


	//get from DB, set in DB
	//int getAllDBAtts();
	//int getDBID();
	//string getDBAttribute();
	//int getDBQuantity();
	//double getDBPrice();
	//void setDBID(int);
	//void setDBAttribute(string);
	//void setDBQuantity(int);
	//void setDBPrice(double);




	//getters and setters, for local stuff
	int getID();
	string getAttribute();
	int getQuantity();
	double getPrice();
	void setID(int);
	void setAttribute(string);
	void setQuantity(int);
	void setPrice(double);



protected:

private:
};

#endif // INVENTORYATTRIBUTES_H

