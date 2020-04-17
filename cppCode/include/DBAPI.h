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

        //Set up constructor and functions
        DBAPI(string db_name, string user, string pass);

        void connectDB();
        void setupDB();


        //customer functions
        void createCustomer();
        void deleteCustomer();
        void getCustomers();

        //inventory item functions
        vector<InventoryItems> createActiveItems();

        //getters for inventory items

        string getItemName(int id);
        string getItemCategory(int id);
        string getItemDescription(int id);

        int getImageID(int id);

        //getters that return BOOLS
        boolean isActive(int id);


        //getters that return something

        vector<int> getActiveIds();



       

};







#endif