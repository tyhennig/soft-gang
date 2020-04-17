#include <iostream>
#include "include/Register.h"
#include "include/InventoryItems.h"
#include "include/InventoryAttributes.h"
#include "include/Product.h"
#include "include/DBAPI.h"


string db_name;
string user;
string pass;

boolean run = true;
int input;


using namespace std;

int main()
{

    
    db_name = "master";
    user = "admin";
    pass = "password";

    DBAPI db(db_name, user, pass);
    db.connectDB();

    while (run)
    {
        cout << "1. List Customers" << endl;
        cout << "2. Create Customer" << endl;
		cout << "3. Delete Customer" << endl;
		cout << "4. Quit" << endl;


        cin >> input;

        if (input == 1)
        {
            db.getCustomers();
        }
        else if (input == 2)
        {
            db.createCustomer();
        }
        else if (input == 3)
        {
            db.deleteCustomer();
		}
		else if (input == 4)
		{
            run = false;
		}
        else
        {
            cout << "Invalid input please select 1-4..." << endl;
        }


    }

    
}
