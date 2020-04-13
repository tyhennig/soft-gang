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




        //getters and setters, to be modified.
        //will pill/push from database and have built in logic
        int getID();
        string getAttribute();
        int getQuantity();
        double getPrice();
        void setID(int);
        void setAttribute(string);
        void setQuantity(int);
        void setPrice(double);



    protected:

    private:
};

#endif // INVENTORYATTRIBUTES_H
