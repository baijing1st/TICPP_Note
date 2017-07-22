#include "stdafx.h"
#include "AssociativeBasics.h"
#include <cstddef>
#include <iterator>
#include <map>
#include <set>
#include "Noisy.h"

using namespace std;

AssociativeBasics::AssociativeBasics()
{
}


AssociativeBasics::~AssociativeBasics()
{
}

void AssociativeBasics_Test::Run()
{
	{
		Noisy na[7];
		set<Noisy> ns(na, na + sizeof na / sizeof(Noisy));
		Noisy n;
		ns.insert(n);
		cout << endl;
		cout << "ns.count(n) = " << ns.count(n) << endl;
		if (ns.find(n) != ns.end())
		{
			/*ostream_iterator<Noisy>(cout, " ");*/
			cout << "n(" << n << ") found in ns" << endl;
		}
		copy(ns.begin(), ns.end(), ostream_iterator<Noisy>(cout, " "));
	}
	{
		map<int, Noisy> nm;
		for (int i = 0; i < 10;i++)
		{
			nm[i];
		}
		//To be continue
	}
}
