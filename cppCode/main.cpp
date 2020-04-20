#include <iostream>
#include <string>
#include <vector>
#include "Register.h"
#include "InventoryItems.h"
#include "InventoryAttributes.h"
#include "Product.h"
#include "Customer.h"

#include "include/DBAPI.h"


string db_name;
string user;
string pass;

boolean run = true;
int input;

vector<InventoryItems> itemVec;
vector<InventoryAttributes> attVec;

using namespace std;

int main()
{
	
	///*
	db_name = "master";
	user = "ADMIN";
	pass = "beepboop";

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
			//itemVec = db.getActiveItems();
			attVec = db.getAllDBAtts();

			//cout << "The first created item name is: ";
			cout << "Here: " << endl;
			for (int i = 0;i < 2;i++)
			{
				//cout << itemVec[i].getName() << endl;
				cout << attVec[i].getID() << endl;
				cout << attVec[i].getAttribute() << endl;
				cout << attVec[i].getQuantity() << endl;
				cout << attVec[i].getPrice() << endl;

			}
			

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

	//*/
	
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
	//Product::clearCart();
	Register::transactionPrompt();
	*/

	

	
}
