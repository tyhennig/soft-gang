#ifndef INVENTORYITEMS_H
#define INVENTORYITEMS_H
#include <iostream>

using namespace std;

class InventoryItems
{
    public:
        InventoryItems();
        InventoryItems(string n, string c, string d, bool a);
        ~InventoryItems();
        string name;
        string category;
        string description;
        bool active;

    protected:

    private:
};

#endif // INVENTORYITEMS_H
