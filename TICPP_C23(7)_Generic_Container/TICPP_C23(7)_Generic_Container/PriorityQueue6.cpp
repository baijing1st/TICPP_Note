#include "stdafx.h"
#include "PriorityQueue6.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <queue>
#include <iostream>

using namespace std;


PriorityQueue6::PriorityQueue6()
{
}


PriorityQueue6::~PriorityQueue6()
{
}

template<class T, class Compare>
class PQV2 : public vector<T>
{
	Compare comp;
	bool sorted;

	void assureHeap()
	{
		if (sorted)
		{
			//Turn it back into a heap
			make_heap(this->begin(), this->end(), comp);
			sorted = false;
		}
	}

public:
	PQV2(Compare cmp = Compare()) :comp(cmp)
	{
		make_heap(this->begin(), this->end(), comp);
		sorted = false;
	}

	const T& top() 
	{
		assureHeap();
		return this->front();
	}

	void push(const T& x)
	{
		assureHeap();
		this->push_back(x);
		push_heap(this->begin(), this->end(), comp);
	}
	void pop()
	{
		assureHeap();
		pop_heap(this->begin(), this->end(), comp);
		this->pop_back();
	}

	void sort()
	{
		if (!sorted)
		{
			sort_heap(this->begin(), this->end(), comp);
			reverse(this->begin(), this->end());
			sorted = true;
		}
	}
};

void PriorityQueue6_Test::Run()
{
	PQV2<int, less<int> > pqi;
	srand(time(0));
	for (int i = 0; i < 10;i++)
	{
		pqi.push(rand() % 25);
		copy(pqi.begin(), pqi.end(), ostream_iterator<int>(cout, " "));
		cout << "\n---------\n" << endl;

	}
	cout << "\n---sort---\n" << endl;
	pqi.sort();
	copy(pqi.begin(), pqi.end(), ostream_iterator<int>(cout, " "));
	cout << "\n---------"<<endl;
	cout << "\n---pop---\n" << endl;
	while (!pqi.empty())
	{
		cout << pqi.top() << ' ';
		pqi.pop();
	}
}
