#include <iostream>
#include <string>
#include <vector>
#include "include/Register.h"
#include "include/InventoryItems.h"
#include "include/InventoryAttributes.h"
#include "include/Product.h"
#include "include/Customer.h"
#include "include/DBAPI.h"


string db_name;
string user;
string pass;

boolean run = true;
int input;

vector<InventoryItems> itemVec;

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
        //cout << "2. Create Customer" << endl;
		//cout << "3. Delete Customer" << endl;
		cout << "4. Quit" << endl;


        cin >> input;

        if (input == 1)
        {
           itemVec = db.createActiveItems();

           cout << "The first created item name is: ";
           cout << itemVec[0].getName() << endl;

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

    /*
	
	InventoryItems x("porky shirt", "shirt", "a blue porky shirt", 1);
    InventoryAttributes y(1, "small", 13, 15.00);
    Product z(x, y);

    InventoryItems a("A&I Logo shirt", "shirt", "a gray porky shirt", 1);
    InventoryAttributes b(1, "small", 4, 15.00);
    Product c(a, b);

    Customer c1("Joe", "Mama", "2463723667", "mamajorunus@gmail.com");



    //Register::openingPrompt();
    //cout << z.getSelected() << endl;
    z.incBtn();
    z.incBtn();
    z.incBtn();
    z.incBtn();
    c.incBtn();

    z.addToCartBtn();
    c.addToCartBtn();
    Product::clearCart();
    Register::transactionPrompt();
    */
}
