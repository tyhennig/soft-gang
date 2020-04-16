#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>

using namespace std;


class Customer
{
    public:
        Customer(string f, string l, string p, string e);
        ~Customer();

        string first;
        string last;
        string phone;
        string email;

        //void addNewCustomer();
        //void removeCust();


        //getters and setters, to be modified.
        //will pill/push from database and have built in logic
        string getFirst();
        string getLast();
        string getPhone();
        string getEmail();
        void setFirst(string);
        void setLast(string);
        void setPhone(string);
        void setEmail(string);

    protected:

    private:
};

#endif // CUSTOMER_H