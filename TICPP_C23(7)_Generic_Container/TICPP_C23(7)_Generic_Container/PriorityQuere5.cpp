#include "stdafx.h"
#include "PriorityQuere5.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <queue>
#include <iostream>

using namespace std;


PriorityQuere5::PriorityQuere5()
{
}


PriorityQuere5::~PriorityQuere5()
{
}

template<class T,class Compare>
class PQV :public vector<T>
{
	Compare comp;
public:
	PQV(Compare cmp = Compare()) :comp(cmp)
	{
		make_heap(this->begin(), this->end(), comp);
	}

	const T& top(){ return this->front(); }

	void push(const T& x)
	{
		this->push_back(x);
		push_heap(this->begin(), this->end(), comp);
	}
	void pop()
	{
		pop_heap(this->begin(), this->end(), comp);
		this->pop_back();
	}
};

void PriorityQuere5_Test::Run()
{
	PQV<int, less<int> > pqi;
	srand(time(0));
	for (int i = 0; i<100;i++)
	{
		pqi.push(rand() % 25);
	}
	copy(pqi.begin(), pqi.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	while (!pqi.empty())
	{
		cout << pqi.top() << ' ';
		pqi.pop();
	}
	//cout << endl << "make_heap():" << endl;

	//make_heap(pqi.begin(), pqi.end(), less<int>());
	//copy(pqi.begin(), pqi.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;
	//while (!pqi.empty())
	//{
	//	cout << pqi.top() << ' ';
	//	pqi.pop();
	//}
}
