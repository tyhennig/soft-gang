#include "../include/DBAPI.h"
#include <iostream>

using namespace std;

DBAPI::DBAPI(string connectionString)
{
    m_connectionString = connectionString;
    //setConnectionString(connectionString);
}



void DBAPI::setConnectionString(string connectionString)
{
    connectionString = m_connectionString;
}

void DBAPI::connectDB(string connectionString)
{

}

void DBAPI::setupDB()
{

}

string DBAPI::getConnectionString()
{
    return m_connectionString;
}

string DBAPI::getInventory_Items(int id)
{
    //query database: SELECT * FROM inventory_items WHERE id = id
    //take string "id, name, category, description, active, imageID"
    //parse string later to extract data.
}