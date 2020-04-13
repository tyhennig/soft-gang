#include "Customer.h"

Customer::Customer(string f, string l, string p, string e)
{
    first = f;
    last = l;
    phone = p;
    email = e;
}

Customer::~Customer()
{
    //dtor
}

string Customer::getFirst()
{
    return first;
}

string Customer::getLast()
{
    return last;
}

string Customer::getPhone()
{
    return phone;
}

string Customer::getEmail()
{
    return email;
}

void Customer::setFirst(string f)
{
    phone = f;
}

void Customer::setLast(string l)
{
    last = l;
}

void Customer::setPhone(string p)
{
    phone = p;
}

void Customer::setEmail(string e)
{
    email = e;
}

