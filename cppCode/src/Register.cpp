#include "Register.h"


Register::Register()
:thisProduct()
{
    //ctor
}


Register::~Register()
{
    //dtor
}

void Register::transactionPrompt()
{
    double total = Product::getTotal();
    double cashGiven;
    double change;

    cout << "These are the items in your cart: " << endl;
    Product::printCart();
    cout << "Your total comes out to $" << total << endl;
    cout << "Please input cash given" << endl;
    cin >> cashGiven;


    while(cashGiven < total)
    {
        cout << "Cash given does not meet total. Enter new cash value with more cash." << endl;
        cin >> cashGiven;
    }
    if(cashGiven >= total)
    {
        change =  total - cashGiven;
        if(change < 0) change *= -1.00;
    }

    cout << "Your change is $" << change <<endl;
    cout << "Thank you for your purchase!" << endl;



}


