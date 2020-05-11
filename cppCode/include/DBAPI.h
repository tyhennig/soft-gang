#ifndef DBAPI_H
#define DBAPI_H

#include "InventoryItems.h"
#include "InventoryAttributes.h"
#include "Customer.h"
#include "Product.h"

#include <vector>
#include <iostream>
#include <SQLAPI.h>


using namespace std;

class DBAPI
{

private:
	string db_name;
	string user;
	string pass;
	SAConnection con;


public:
	


	//------------------------------------------------------------
	//CLASS FUNCTIONS
	//------------------------------------------------------------
	DBAPI(string db_name, string user, string pass);
	void connectDB();


	//------------------------------------------------------------
	//CUSTOMER FUNCTIONS
	//------------------------------------------------------------
	void createCustomer(Customer customer);
	void deleteCustomer(Customer customer);
	void editCustomer(Customer customer);

	vector<Customer> getCustomers();


	//------------------------------------------------------------
	//INVENTORY ITEM FUNCTIONS
	//------------------------------------------------------------

	void createItem();
	void deleteItem();

	vector<InventoryItems> getActiveItems(); //returns a vector containing all active item objects
	vector<int> getActiveIds();

	int getImageID(int id);

	boolean isActive(int id);

	//------------------------------------------------------------
	//INVENTORY ATTRIBUTE FUNCTIONS
	//------------------------------------------------------------

	//Abraham added functions
	vector<InventoryAttributes> getAllDBAtts();
	//---------------
	void createAttribute();
	void deleteAttribute();

	//this will be an attribute for 
	//makeProducts(vector<InventoryItems>, vector<InventoryAttributes>) class
	//in Product.h
	//vector<InventoryAttributes> getAttributes(int id);



	//------------------------------------------------------------
	//PURCHASE FUNCTIONS
	//------------------------------------------------------------
	void updateQuantity(vector<Product> prod);

	void createPurchase();
	void executePurchase();

};







#endif

