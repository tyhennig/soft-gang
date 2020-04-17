#include "../include/Product.h"

vector<Product> Product::cart;
double Product::total = 0.00;
Product::Product()
{

}

Product::Product(InventoryItems iI, InventoryAttributes iA)
:thisItem(iI),thisAtt(iA)
{

}

Product::~Product()
{
    //dtor
}

void Product::printCard()
{
    cout << "name: " << (*this).thisItem.getName() << endl;
    //cout << "description: " << (*this).thisItem.getDescription() << endl;
    cout << "price: $" << (*this).thisAtt.getPrice() << endl;
    //cout << "in stock: " << (*this).thisAtt.getQuantity() << endl;
}

void Product::addToCartBtn()
{
    for(int i = 0; i < selected; i++)
    cart.push_back(*this);

    //this may need to be moved into the for loop, depending on design
    //keeping it outside is more efficient
    (*this).thisAtt.setQuantity((*this).thisAtt.getQuantity()-selected);

}

void Product::remFromCart()
{
    //this method needs more work. The intention is to delete a specific object, but the line below will always get rid of cart[1]
    cart.erase(cart.begin() + 1);
}

void Product::clearCart()
{
    cart.clear();
}

void Product::printCart()
{
    for(unsigned int i = 0; i < cart.size(); i++) {
        cart[i].printCard();
    }
    cout << endl;
}

double Product::getTotal()
{
    for(unsigned int i = 0; i < cart.size(); i++){

        total += cart[i].thisAtt.getPrice();
    }
    return total;
}

int Product::getSelected()
{
    return selected;
}

void Product::incBtn()
{
    if(selected <= (*this).thisAtt.getQuantity()) selected++;
}

void Product::decBtn()
{
    if(selected > 0) selected--;
}




//will take in money given
//maybe override method two have cash and card option. or include logic within
void finalPurchaseBtn()
{



    //will change values inside the database with local values
    //will initialize statistical data
}
