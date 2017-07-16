#include "stdafx.h"
#include "BankTeller.h"

using namespace std;
BankTeller::BankTeller()
{
}


BankTeller::~BankTeller()
{
}

class Customer
{
	int serviceTime;
public:
	Customer() :serviceTime(0) {}
	Customer(int tm) :serviceTime(tm) {}
	int getTime() { return serviceTime; }
	void setTime(int newtm) { serviceTime = newtm; }
	friend ostream& operator<<(ostream& os, const Customer& c)
	{
		return os << '[' << c.serviceTime << ']';
	}
};

class Teller
{
	queue<Customer>& customers;
	Customer current;
	const int islice = 5;
	int ttime;	//Time left in slice
	bool busy;	//Is Teller serving a customer
public:
	Teller(queue<Customer>& cq) :customers(cq), ttime(0), busy(false) {}
	Teller& operator=(const Teller& rv)
	{
		customers = rv.customers;
		current = rv.current;
		ttime = rv.ttime;
		busy = rv.busy;
		return *this;
	}

	bool isBusy() { return busy; }
	void run(bool recursion = false)
	{
		if (!recursion)
		{
			ttime = islice;
		}
		int servtime = current.getTime();
		if (servtime > ttime)
		{
			servtime -= ttime;
			current.setTime(servtime);
			busy = true;
			return;
		}
		else if (servtime < ttime)
		{
			ttime -= servtime;
			if (!customers.empty())
			{
				current = customers.front();
				customers.pop();
				busy = true;
				run(true);
			}
		}
		else if(servtime == ttime)
		{
			current = Customer(0);
			busy = false;
			return;
		}
	}
};

class CustomerQ : public queue<Customer>
{
public:
	friend ostream&
		operator<<(ostream& os, const CustomerQ& cd)
	{
		copy(cd.c.begin(), cd.c.end(), ostream_iterator<Customer>(os, " "));
		return os ;
	}
};

void BankTeller_Test::Run()
{
	CustomerQ customers;
	list < Teller> tellers;
	typedef list<Teller>::iterator TellIt;
	tellers.push_back(Teller ( customers));
	srand(time(0));
	clock_t ticks = clock();
	while (clock()<ticks + 5*CLOCKS_PER_SEC)
	{
		for (int i = 0; i<rand()%5;i++)
		{
			customers.push(Customer(rand() % 15 + 1));
		}
		cout << "Before Run tellers.size() = " << '{' << tellers.size() << '}' << customers << endl;
		for (TellIt i = tellers.begin();i!= tellers.end();i++)
		{
			(*i).run();
		}
		cout << "After Run tellers.size() = "<<'{' << tellers.size() << '}' << customers << endl;

		//If too long, add another teller
		if (customers.size()/tellers.size()>2)
		{
			tellers.push_back(Teller(customers));
		}
		if (tellers.size() > 1 && customers.size() / tellers.size() < 2)
		{
			for(TellIt it = tellers.begin(); it!=tellers.end();it++)
				if (!(*it).isBusy())
				{
					tellers.erase(it);
					break;
				}
		}
	}

}
