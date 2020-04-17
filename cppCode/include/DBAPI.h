#ifndef DBAPI_H
#define DBAPI_H
 
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


        void createCustomer();
        void deleteCustomer();
        void getCustomers();

        //getters that return strings

        string getName(int id);
        string getCategory(int id);
        string getDescription(int id);

        //getters that return BOOLS
        boolean isActive(int id);


        //getters that return ints
        int getActive();
        int getImageID(int id);



        //We either do all of this stuff ^ and get every single attribute
        //of every single table or we can do something like this

        string getInventory_Items(int id);

};







#endif