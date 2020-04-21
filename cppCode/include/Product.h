#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include<vector>
#include "InventoryItems.h"
#include "InventoryAttributes.h"
#include "DBAPI.h"


using namespace std;

class Product
{
public:
	Product();
	Product(InventoryItems, InventoryAttributes);
	
	~Product();

	InventoryItems thisItem;
	InventoryAttributes thisAtt;
	static vector<Product> cart;


	static vector<InventoryItems> itemsVector;
	static vector<InventoryAttributes> attsVector;
	static vector<Product> DBProducts;
	static double total;
	int selected = 0;



	void printCard();
	//the bottom two need work. Depends on how the design is carried out
	static void clearCart();
	void remFromCart();
	static void printCart();
	static double getTotal();
	int getSelected();

	void incBtn();
	void decBtn();
	void addToCartBtn();

	static vector<Product> makeProducts(vector<InventoryItems> & II, vector<InventoryAttributes> & IA);
	static void printDBProducts();
	//TODO: Implement methods in object oriented fashion
	//      Find out whether you even have to. Learn about sql c++ first maybe
	//addProduct();
	//removeProduct();
	//returnItem();




protected:

private:
};

#endif // PRODUCT_H

