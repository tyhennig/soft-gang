#include "DBAPI.h"
#include <iostream>

/*
::::::::::::TODO IMPORTANT:::::::::::

Edit items from cart


*/






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




//-----------------------------------------------

//Inventory Item Related Methods

//-----------------------------------------------

vector<InventoryItems> DBAPI::getActiveItems()
{
	int numItems = 0;
	vector<InventoryItems> itemsVector;

	try
	{
		SACommand cmd(
			&con,
			"SELECT id, name, category, description, imageID FROM inventory_items WHERE active=1;"
		);

		cmd.Execute();

		while (cmd.FetchNext())
		{
			numItems++;
			itemsVector.resize(numItems);


			int id;
			string name;
			string category;
			string description;
			string imageID;

			id = (sa_int64_t)cmd.Field(1).asNumeric();
			name = (const char*)cmd.Field(2).asString();
			category = (const char*)cmd.Field(3).asString();
			description = (const char*)cmd.Field(4).asString();
			imageID = (const char*)cmd.Field(5).asString();

			itemsVector[numItems - 1].setID(id);
			itemsVector[numItems - 1].setName(name);
			itemsVector[numItems - 1].setCategory(category);
			itemsVector[numItems - 1].setDescription(description);
		}

		return itemsVector;

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


vector<int> DBAPI::getActiveIds()
{
	vector<int> vec;
	return vec;
}

/*string DBAPI::getItemName(int id)
{
	return "name";
}*/

//-----------------------------------------------

//Customer Related Methods:

//-----------------------------------------------

void DBAPI::createCustomer(Customer customer)
{

	string first = customer.first;
	string last = customer.last;
	string phone = customer.phone;
	string email = customer.email;

	try
	{
		SACommand cmd(
			&con,
			"INSERT INTO customers VALUES (:1, :2, :3, :4)"
		);

		cmd.Param(1).setAsString() = first.c_str();
		cmd.Param(2).setAsString() = last.c_str();
		cmd.Param(3).setAsString() = phone.c_str();
		cmd.Param(4).setAsString() = email.c_str();


		cmd.Execute();


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

void DBAPI::deleteCustomer(Customer customer)
{

	string first;
	string last;


	try
	{
		SACommand cmd(
			&con,
			"DELETE FROM customers WHERE first=:1 AND last=:2;"
		);

		cout << "Customer First Name: ";
		cin >> first;
		cout << endl << "Customer Last Name: ";
		cin >> last;

		cmd.Param(1).setAsString() = first.c_str();
		cmd.Param(2).setAsString() = last.c_str();
		

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

vector<Customer> DBAPI::getCustomers()
{
	try
	{

		SACommand cmd(
			&con,
			"SELECT first, last, phone, email FROM customers;"
		);

		cmd.Execute();


		if (cmd.isResultSet())
		{

			while (cmd.FetchNext())
			{
				cout << (const char*)cmd.Field("first").asString() << " " <<
					(const char*)cmd.Field("last").asString() << endl;

			}

		}
		vector<Customer> cvec;
		return cvec;

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


vector<InventoryAttributes> DBAPI::getAllDBAtts()
{
	int numAttributes = 0;
	vector<InventoryAttributes> attributesVector;

	try
	{
		SACommand cmd(
				&con,
				"Select attributeID, itemID, attribute, quantity, price FROM inventory_attributes;"
		);

		cmd.Execute();

		while (cmd.FetchNext())
		{
			numAttributes++;
			attributesVector.resize(numAttributes);

			int attID;
			int itemID;
			string attribute;
			int quantity;
			double price;

			attID = (sa_int64_t)cmd.Field(1).asNumeric();
			itemID = (sa_int64_t)cmd.Field(2).asNumeric();
			attribute = (const char*)cmd.Field(3).asString();
			quantity = (sa_int64_t)cmd.Field(4).asNumeric();
			price = (double)cmd.Field(5).asNumeric();

			attributesVector[numAttributes - 1].setAttID(attID);
			attributesVector[numAttributes - 1].setID(itemID);
			attributesVector[numAttributes - 1].setAttribute(attribute);
			attributesVector[numAttributes - 1].setQuantity(quantity);
			attributesVector[numAttributes - 1].setPrice(price);
		}
			return attributesVector;
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



void DBAPI::updateQuantity(vector<Product> prodVector)
{

	int numItems = prodVector.size();
	for (int i = 0; i < numItems; i++)
	{

	try
	{
		SACommand cmd(
			&con,
			"UPDATE inventory_attributes SET quantity = quantity - 1 WHERE attributeID = :1;"
		);

		cmd.Param(1).setAsInt64() = prodVector[i].thisAtt.getAttID();

		cmd.Execute();


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




}

void DBAPI::executePurchase()
{


}
