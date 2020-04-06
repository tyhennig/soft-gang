#include "../include/DBAPI.h"
#include <iostream>

using namespace std;

DBAPI::DBAPI(string connectionString)
{
    setConnectionString(connectionString);
}



void DBAPI::setConnectionString(string connectionString)
{
    connectionString = m_connectionString;
}

void DBAPI::connectDB(string connectionString)
{
    
}

string DBAPI::getConnectionString()
{
    return m_connectionString;
}