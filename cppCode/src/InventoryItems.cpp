#include "../include/InventoryItems.h"

InventoryItems::InventoryItems()
{
    //ctor
}

InventoryItems::InventoryItems(string n, string c, string d, bool a)
{
    name = n;
    category = c;
    description = d;
    active = a;
}

InventoryItems::~InventoryItems()
{
    //dtor
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


