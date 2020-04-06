#ifndef DBAPI_H
#define DBAPI_H

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include <iostream>

using namespace std;

class DBAPI
{

    private:
        string m_connectionString;

    public:
        //Set up constructor and functions
        DBAPI(string connectionString);
        void setConnectionString(string connectionString);
        void connectDB(string connectionSTring);
        void setupDB();

        //getters that return strings
        string getConnectionString();

        string getName(int id);
        string getCategory(int id);
        string getDescription(int id);

        //getters that return BOOLS
        boolean getActive(int id);


        //getters that return ints
        int getNumActive();
        int * getActiveIDs();   //returns pointer to array of active IDs
        int getImageID(int id);



        //We either do all of this stuff ^ and get every single attribute
        //of every single table or we can do something like this

        string getInventory_Items(int id);

};







#endif