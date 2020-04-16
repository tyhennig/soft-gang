#include <iostream>
#include <string>
#include <vector>
#include "include/Register.h"
#include "include/InventoryItems.h"
#include "include/InventoryAttributes.h"
#include "include/Product.h"
#include "include/Customer.h"
#include "include/DBAPI.h"
#include "src/DBAPI.cpp"

string CONNECT_ST = "Server=(localdb).\\MSSQLLocalDB;Integrated Security=true";

using namespace std;
int main()
{

        DBAPI db(CONNECT_ST);
        cout << db.getConnectionString() << endl;

        db.connectDB(CONNECT_ST);
        cout << "done!" << endl;
    
	
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
}
