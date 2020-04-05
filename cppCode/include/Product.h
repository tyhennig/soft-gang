#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include "InventoryItems.h"
#include "InventoryAttributes.h"


using namespace std;

class Product
{
    public:
        Product();
        Product(InventoryItems, InventoryAttributes);
        ~Product();
        InventoryItems thisItem;
        InventoryAttributes thisAtt;

        //TODO: Implement methods in object oriented fashion
        //      Find out whether you even have to. Learn about sql c++ first maybe
        //addProduct();
        //removeProduct();
        //addToCart();
        //calcTotal();
        //calcChange();
        //transaction();
        //returnItem();




    protected:

    private:
};

#endif // PRODUCT_H
