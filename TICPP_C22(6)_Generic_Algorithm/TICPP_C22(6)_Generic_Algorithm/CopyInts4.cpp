#include "stdafx.h"
#include "CopyInts4.h"
#include <algorithm>
#include <cstddef>
#include<functional>
#include <iostream>
using namespace std;

CopyInts4::CopyInts4()
{
}


CopyInts4::~CopyInts4()
{
}


void CopyInts4_Test::Run()
{
	int a[] = { 10,20,30 };
	const size_t size = sizeof a / sizeof a[0];
	int b[size];
	//remove_copy_if(a, a + size, b, bind2nd(greater<int>(), 15));
	remove_copy_if(a, a + size, b, bind1st(greater<int>(),15));
	int * beginb = b;
	int *endb = b + size;

	while (beginb!=endb)
	{
		cout << *beginb++ << endl;
	}
}
