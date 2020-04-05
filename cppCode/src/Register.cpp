#include "Register.h"

Register::Register()
{
    //ctor
}

Register::Register(Product p, int q, int c)
:thisProduct(p)
{
    quantity = q;
    cashGiven = c;
}

Register::~Register()
{
    //dtor
}

double Register::calcChange(double c, double p, int q)
{
    cashGiven = c;
    price = p;
    quantity = q;

    total = price * quantity;
    return change = cashGiven - total;
}


