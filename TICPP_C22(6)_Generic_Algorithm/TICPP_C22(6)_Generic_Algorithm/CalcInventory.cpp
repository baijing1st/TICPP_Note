#include "stdafx.h"
#include "CalcInventory.h"

using namespace std;

class InvAccum
{
	int quantity;
	int value;
public:
	InvAccum() :quantity(0), value(0) {}
	~InvAccum();

	void operator()(const Inventory& inv)
	{
		quantity += inv.getQuantity();
		value += inv.getValue();
	}

	friend ostream& operator<<(ostream& os, const InvAccum& ia)
	{
		return os << "total quantity: " << ia.quantity
			<< ", total value: " << ia.value;
	}

private:

};



InvAccum::~InvAccum()
{
}


CalcInventory::CalcInventory()
{
}


CalcInventory::~CalcInventory()
{
}

void CalcInventory_Test::Run()
{
	vector<Inventory> vi;
	srand(time(0));
	generate_n(back_inserter(vi), 15, InvenGen());
	print(vi.begin(), vi.end(), "vi");
	InvAccum ia = for_each(vi.begin(), vi.end(), InvAccum());
	cout << ia << endl;

}
