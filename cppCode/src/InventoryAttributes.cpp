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
