#pragma once
#include <iostream>
#include <cstdlib>

using std::rand;

class Inventory
{
	char item;
	int quantity;
	int value;
public:

	Inventory(char it, int quant, int val)
		:item(it),quantity(quant),value(val){}

	~Inventory()
	{
	}
	char getItem() const { return item; }
	int getQuantity() const { return quantity; }
	int getValue() const {	return value;}
	void setQuantity(int q) { quantity = q; }
	void setValue(int v) { value = v; }

	friend std::ostream& operator<<(std::ostream& os,const Inventory& inv)
	{
		return os << inv.item << ": "
			<< "quantity " << inv.quantity
			<< ", value" << inv.value << std::endl;
	}
};

struct InvenGen
{
	Inventory operator()()
	{
		static char c = 'a';
		int q = rand() % 100;
		int v = rand() % 500;
		return Inventory(c++, q, v);
	}
};

