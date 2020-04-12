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
