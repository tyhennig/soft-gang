#include "../include/DBAPI.h"
#include <iostream>


using namespace std;


DBAPI::DBAPI(string db_name, string user, string pass)
{
    this->db_name = db_name;
    this->user = user;
    this->pass = pass;
}



void DBAPI::connectDB()
{
    

    
    try {

        con.Connect(db_name.c_str(), user.c_str(), pass.c_str(), SA_SQLServer_Client);
		cout << "connected!" << endl << endl;
        
    }
    catch (SAException& x) {
        con.Rollback();
        cout << (const char*)x.ErrText();
        }
    

}

void DBAPI::setupDB()
{

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

string DBAPI::getName(int id)
{
    return "name";
}

void DBAPI::createCustomer()
{

	try
	{
		SACommand cmd(
			&con,
			"INSERT INTO customers (first, last, phone, email) VALUES ('k', 'k', '314', 'k@gmail.com');"
		);

		cmd.Execute();

		cout << endl << "Rows Affected: " << cmd.RowsAffected() << endl;

		

	}
	catch (SAException& x)
	{
		try
		{
			con.Rollback();
		}
		catch (SAException&)
		{

		}

		cout << (const char*)x.ErrText() << endl;

	}
	
}

void DBAPI::deleteCustomer()
{
	
	try
	{

        SACommand cmd(
		&con,
		"DELETE FROM customers WHERE first='k';"
	);

	cmd.Execute();

	cout << endl << "Rows Affected: " << cmd.RowsAffected() << endl;

	}
	catch (SAException& x)
	{
		try
		{
			con.Rollback();
		}
		catch (SAException&)
		{

		}

		cout << (const char*)x.ErrText() << endl;

	}
}

void DBAPI::getCustomers()
{
    try
    {

		SACommand cmd(
			&con,
			"SELECT first FROM customers;"
		);

		cmd.Execute();


		if (cmd.isResultSet())
		{

			while (cmd.FetchNext())
			{
				cout << (const char*)cmd.Field("first").asString() << endl;
			}

		}

    }
    catch (SAException &x)
    {
        try
        {
            con.Rollback();
        }
        catch (SAException &)
        {

        }

        cout << (const char*)x.ErrText() << endl;

    }
	

}