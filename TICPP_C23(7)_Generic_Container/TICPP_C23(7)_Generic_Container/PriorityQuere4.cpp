#include "stdafx.h"
#include "PriorityQuere4.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <queue>
#include <iostream>

using namespace std;

PriorityQuere4::PriorityQuere4()
{
}


PriorityQuere4::~PriorityQuere4()
{
}

class PQI: public priority_queue<int>
{
	public:
		vector<int>& impl() { return c; }
};

void PriorityQuere4_Test::Run()
{
	PQI pqi;
	srand(time(0));
	for (int i = 0; i<100;i++)
	{
		pqi.push(rand() % 25);
	}
	copy(pqi.impl().begin(), pqi.impl().end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	while (!pqi.empty())
	{	
		cout << pqi.top() << ' ';
		pqi.pop();
	}
}
