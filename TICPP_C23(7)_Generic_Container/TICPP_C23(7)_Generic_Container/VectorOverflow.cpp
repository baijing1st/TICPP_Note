#include "stdafx.h"
#include "VectorOverflow.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Noisy.h"

using namespace std;

VectorOverflow::VectorOverflow()
{
}


VectorOverflow::~VectorOverflow()
{
}

void VectorOverflow_Test::Run()
{
	int size = 1000;
	vector<Noisy> vn;
	Noisy n;
	for (int i = 0; i<size; i++)
	{
		vn.push_back(n);
	}
	cout << "\n Cleaning up" << endl;
	

}