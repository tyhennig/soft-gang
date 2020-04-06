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

        //getters that return ints
        int getNumActive();
        int * getActiveIDs();   //returns pointer to array of active IDs
        int getName(int id);



};







#endif