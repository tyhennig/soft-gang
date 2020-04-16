#include "../include/DBAPI.h"
#include <iostream>
#define MYSQLSUCCESS(rc) ((rc == SQL_SUCCESS) || (rc == SQL_SUCCESS_WITH_INFO) )

using namespace std;

RETCODE rc;

DBAPI::DBAPI(string connectionString)
{
    m_connectionString = connectionString;


}



void DBAPI::setConnectionString(string connectionString)
{
    connectionString = m_connectionString;
}

void DBAPI::connectDB(string connectionString)
{
    SQLAllocEnv(&henv1);
    SQLAllocConnect(henv1, &hdbc1);

    //SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv1);
    //SQLSetEnvAttr(henv1, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
    //SQLAllocHandle(SQL_HANDLE_DBC, henv1, &hdbc1);
    rc = SQLConnectW(hdbc1, (SQLWCHAR *)"localhost\\SQLEXPRESS", SQL_MAX_DSN_LENGTH, NULL, NULL, NULL, NULL);
    cout << "started connection..." << endl;

    if (!MYSQLSUCCESS(rc))
    {
        SQLFreeConnect(henv1);
        SQLFreeEnv(henv1);
        SQLFreeConnect(hdbc1);
        cout << "connection failed!" << endl;

    }
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
    if(id <= 0)
    {
    return "inventory items";
    } else
    {
        return "no item";
    }
    
    //query database: SELECT * FROM inventory_items WHERE id = id
    //take string "id, name, category, description, active, imageID"
    //parse string later to extract data.
}