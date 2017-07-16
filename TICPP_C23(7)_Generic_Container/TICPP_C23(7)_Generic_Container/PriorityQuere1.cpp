#include "stdafx.h"
#include "PriorityQuere1.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>

using namespace std;


PriorityQuere1::PriorityQuere1()
{
}


PriorityQuere1::~PriorityQuere1()
{
}

void PriorityQuere1_Test::Run()
{
	priority_queue<int> pqi;
	srand(time(0));
	for (int i = 0;i<100;i++)
	{
		pqi.push(rand() % 25);
	}
	while (!pqi.empty())
	{
		cout << pqi.top() << ' ';
		pqi.pop();
	}
}