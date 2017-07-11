#include "stdafx.h"
#include "ListStability.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include "Noisy.h"
using namespace std;

ListStability::ListStability()
{
}


ListStability::~ListStability()
{
}

void ListStability_Test::Run()
{
	list<Noisy> l;
	ostream_iterator<Noisy> out(cout, " ");
	generate_n(back_inserter(l), 25, NoisyGen());
	cout << "\n Print the list" << endl;
	copy(l.begin(), l.end(), out);
	cout << "\nReversing the list: " << endl;
	l.reverse();
	copy(l.begin(), l.end(), out);
	cout << "\nSorting the list: " << endl;
	l.sort();
	copy(l.begin(), l.end(), out);
	cout << "\nSwapping two element: " << endl;
	list<Noisy>::iterator it1, it2;
	it1 = it2 = l.begin();
	++it2;
	swap(*it1, *it2);
	cout << endl;
	copy(l.begin(), l.end(), out);
	cout << "\nUsing Generic reverse():" << endl;
	reverse(l.begin(), l.end());
	cout << endl;
	copy(l.begin(), l.end(), out);
	cout << "\nCleanup" << endl;
}
