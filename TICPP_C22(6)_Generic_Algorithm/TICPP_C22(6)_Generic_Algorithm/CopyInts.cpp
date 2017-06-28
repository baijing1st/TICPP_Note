#include "stdafx.h"
#include "CopyInts.h"
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>

using namespace std;

CopyInts::CopyInts()
{
}



CopyInts::~CopyInts()
{
}

void CopyInts_Test::Run()
{
	int a[] = { 10, 20, 30 };
	const size_t SIZE = sizeof a / sizeof a[0];
	int b[SIZE];
	copy(a, a + SIZE, b);
	for (size_t i = 0;i<SIZE;++i)
	{
		cout << "a[" << i << "]=" << a[i] << "    b[" << i << "]=" << b[i] << endl;
		assert(a[i]==b[i]);
	}
}
