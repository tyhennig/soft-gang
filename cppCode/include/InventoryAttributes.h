#ifndef INVENTORYATTRIBUTES_H
#define INVENTORYATTRIBUTES_H
#include <iostream>

using namespace std;

class InventoryAttributes
{
    public:
        InventoryAttributes();
        InventoryAttributes(int id, string att, int q, double p);
        ~InventoryAttributes();
        int itemID;
        string attribute;
        int quantityAv;
        double price;


    protected:

    private:
};

#endif // INVENTORYATTRIBUTES_H
