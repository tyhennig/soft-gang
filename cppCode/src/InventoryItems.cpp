#include "InventoryItems.h"

InventoryItems::InventoryItems()
{
	//ctor
}

InventoryItems::InventoryItems(int id, string n, string c, string d, bool a)
{
	ID = id;
	name = n;
	category = c;
	description = d;
	active = a;
}

InventoryItems::~InventoryItems()
{
	//dtor
}

int InventoryItems::getID()
{
	return ID;
}

string InventoryItems::getName()
{
	return name;
}

string InventoryItems::getCategory()
{
	return category;
}

string InventoryItems::getDescription()
{
	return description;
}

bool InventoryItems::getActive()
{
	return active;
}

void InventoryItems::setID(int i)
{
	ID = i;
}

void InventoryItems::setName(string n)
{
	name = n;
}

void InventoryItems::setCategory(string c)
{
	category = c;
}

void InventoryItems::setDescription(string d)
{
	description = d;
}

void InventoryItems::setActive(bool a)
{
	active = a;
}



