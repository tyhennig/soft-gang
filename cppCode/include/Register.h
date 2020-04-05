#ifndef REGISTER_H
#define REGISTER_H
#include<iostream>
#include "Product.h"

using namespace std;


class Register
{
    public:
        Register();
        Register(Product p, int q, int c);
        ~Register();
        Product thisProduct;
        double price;
        double total;
        double change;
        double cashGiven;
        int quantity;
        double calcChange(double c, double p, int q);




    protected:

    private:
};

#endif // REGISTER_H
