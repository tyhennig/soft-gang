#ifndef REGISTER_H
#define REGISTER_H
#include<iostream>
#include<vector>
#include "Product.h"

using namespace std;


class Register
{
    public:
        Register();
        ~Register();
        Product thisProduct;

        static void transactionPrompt();


    protected:

    private:
};

#endif // REGISTER_H
