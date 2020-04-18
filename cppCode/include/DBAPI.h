#ifndef DBAPI_H
#define DBAPI_H

#include "InventoryItems.h"
#include "InventoryAttributes.h"

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
        void createCustomer();
        void deleteCustomer();
        void editCustomer(int id);
        void editCustomer(string first, string last);

        void getCustomers();

		
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

        void createAttribute();
        void deleteAttribute();

        vector<InventoryAttributes> getAttributes(int id);

        

		//------------------------------------------------------------
		//PURCHASE FUNCTIONS
		//------------------------------------------------------------

        void createPurchase();
        void executePurchase();

};







#endif