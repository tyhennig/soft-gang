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

        //getters and setters, to be modified.
        //will pill/push from database and have built in logic
        string getName();
        string getCategory();
        string getDescription();
        bool getActive();
        void setName(string);
        void setCategory(string);
        void setDescription(string);
        void setActive(bool);

    protected:

    private:
};

#endif // INVENTORYITEMS_H
