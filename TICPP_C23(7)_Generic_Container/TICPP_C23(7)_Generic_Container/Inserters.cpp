#include "stdafx.h"
#include "Inserters.h"
#include <iostream>
#include <vector>
#include<deque>
#include <list>
#include <iterator>
using namespace std;

int a[] = {1,3,5,7,9,11,13,17,19,23};

template <class Cont>void frontInsertion(Cont& ci)
{
	int size = ( sizeof(a) / sizeof(typename Cont::value_type));
	copy(a, a + sizeof(a) / sizeof(typename Cont::value_type), front_inserter(ci));
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(
		cout, " "));
	cout << endl;
}

template <class Cont>void midInsertion(Cont& ci)
{
	typename Cont::iterator it = ci.begin();
	++it;++it;++it;

	copy(a, a + sizeof(a) / (sizeof(typename Cont::value_type)*2), inserter(ci,it));
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(
		cout, " "));
	cout << endl;
}

Inserters::Inserters()
{
}


Inserters::~Inserters()
{
}

void Inserters_Test::Run()
{
	deque<int> di;
	frontInsertion(di);
	//di.clear();
	midInsertion(di);
}
