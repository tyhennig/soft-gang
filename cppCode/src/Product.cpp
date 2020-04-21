#include "Product.h"

vector<Product> Product::cart;
vector<Product> Product::DBProducts;
vector<InventoryItems> Product::itemsVector;
vector<InventoryAttributes> Product::attsVector;

double Product::total = 0.00;
Product::Product()
{

}

Product::Product(InventoryItems iI, InventoryAttributes iA)
	:thisItem(iI), thisAtt(iA)
{

}

Product::~Product()
{
	//dtor
}

void Product::printCard()
{
	cout << "name: " << (*this).thisItem.getName() << endl;
	cout << "size: " << (*this).thisAtt.getAttribute() << endl;
	cout << "description: " << (*this).thisItem.getDescription() << endl;
	cout << "price: $" << (*this).thisAtt.getPrice() << endl;
	cout << "in stock: " << (*this).thisAtt.getQuantity() << endl;
	cout << "------------------------------------------" << endl;
}

void Product::addToCartBtn()
{
	for (int i = 0; i < selected; i++)
		cart.push_back(*this);

	//this may need to be moved into the for loop, depending on design
	//keeping it outside is more efficient
	(*this).thisAtt.setQuantity((*this).thisAtt.getQuantity() - selected);

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
	for (unsigned int i = 0; i < cart.size(); i++) {
		cart[i].printCard();
	}
	cout << endl;
}

double Product::getTotal()
{
	for (unsigned int i = 0; i < cart.size(); i++) {

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
	if (selected <= (*this).thisAtt.getQuantity()) selected++;
}

void Product::decBtn()
{
	if (selected > 0) selected--;
}




//will take in money given
//maybe override method two have cash and card option. or include logic within
void finalPurchaseBtn()
{



	//will change values inside the database with local values
	//will initialize statistical data
}


//functions using DBAPI data

vector<Product> Product::makeProducts(vector<InventoryItems> & II, vector<InventoryAttributes> & IA)
{
	//two possible approaches. Make a multidimensinal array to make up for sizes,
	//or make a Product object for every size. <-doin this one
	

	//fix this loop
	int j = 0;	
	for (int i = 0; i < II.size(); i++) {
		for (j; j < IA.size(); j++) {
			if (II[i].getID() == IA[j].getID()) {
				Product x(II[i], IA[j]);
				DBProducts.push_back(x);
			}
			else break;	
		}
	}
		return DBProducts;
	
			/*
			Product a(II[0], IA[0]);
			DBProducts.push_back(a);
			Product s(II[0], IA[1]);
			DBProducts.push_back(s);
			Product d(II[0], IA[2]);
			DBProducts.push_back(d);

			Product f(II[1], IA[3]);
			DBProducts.push_back(f);
			Product g(II[1], IA[4]);
			DBProducts.push_back(g);
			Product h(II[1], IA[5]);
			DBProducts.push_back(h);

			Product j(II[2], IA[6]);
			DBProducts.push_back(j);
			Product k(II[2], IA[7]);
			DBProducts.push_back(k);
			Product l(II[2], IA[8]);
			DBProducts.push_back(l);
			*/
			
			
		
		
		//cout << DBProducts[0].thisItem.getName() << endl;
		//Product(name, );
	
	
	
}

void Product::printDBProducts()
{

	cout << "Here are all Active Products: " << endl;
	for (unsigned int i = 0; i < DBProducts.size(); i++) {
		DBProducts[i].printCard();
	}
	cout << endl;
}