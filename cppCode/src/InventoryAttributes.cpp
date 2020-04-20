#include "InventoryAttributes.h"

InventoryAttributes::InventoryAttributes()
{
	//ctor
}

InventoryAttributes::InventoryAttributes(int id, string att, int q, double p)
{
	itemID = id;
	attribute = att;
	quantityAv = q;
	price = p;
}

InventoryAttributes::~InventoryAttributes()
{
	//dtor
}

int InventoryAttributes::getID()
{
	return itemID;
}

string InventoryAttributes::getAttribute()
{
	return attribute;
}

int InventoryAttributes::getQuantity()
{
	return quantityAv;
}

double InventoryAttributes::getPrice()
{
	return price;
}

void InventoryAttributes::setID(int i)
{
	itemID = i;
}


void InventoryAttributes::setAttribute(string a)
{
	attribute = a;
}

void InventoryAttributes::setQuantity(int q)
{
	quantityAv = q;
}

void InventoryAttributes::setPrice(double p)
{
	price = p;
}


