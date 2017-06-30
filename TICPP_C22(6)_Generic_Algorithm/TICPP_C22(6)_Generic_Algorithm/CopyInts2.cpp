#include "stdafx.h"
#include "CopyInts2.h"

using namespace std;

bool gt15(int x) { return 15 < x; }

CopyInts2::CopyInts2()
{
}


CopyInts2::~CopyInts2()
{
}


void CopyInts2_Test::Run()
{
	int a[] = {10,20,30};
	const size_t size = sizeof a / sizeof a[0];
	int b[size];
	int *endb = remove_copy_if(a, a + size, b, gt15);
	int *beginb = b;
	while (beginb!=endb)
	{
		cout << *beginb++ << endl;
	}

}


