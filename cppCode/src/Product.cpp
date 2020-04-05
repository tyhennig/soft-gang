#include "Product.h"

Product::Product()
{
    //
}

Product::Product(InventoryItems iI, InventoryAttributes iA)
:thisItem(iI),thisAtt(iA)
{

}

Product::~Product()
{
    //dtor
}
