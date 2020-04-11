#include <iostream>
#include "include/Register.h"
#include "include/InventoryItems.h"
#include "include/InventoryAttributes.h"
#include "include/Product.h"
#include "include/DBAPI.h"
#include "src/DBAPI.cpp"

string CONNECT_ST = "Server=(localdb).\\MSSQLLocalDB;Integrated Security=true";

using namespace std;
int main()
{

        DBAPI db(CONNECT_ST);
        cout << db.getConnectionString() << endl;
        cout << "done!" << endl;
    
}
