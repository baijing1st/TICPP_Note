#include "stdafx.h"
#include "FBinder.h"

using namespace std;

FBinder::FBinder()
{
}


FBinder::~FBinder()
{
}

void FBinder_Test::Run()
{
	ostream_iterator<int> out(cout, "");
	vector<int> v(15);
	srand(time(0));
	generate(v.begin(), v.end(), URandGen(20));
	copy(v.begin(), v.end(), out);
	transform(v.begin(), v.end(), v.begin(), bind2nd(multiplies<int>(), 10));
	copy(v.begin(), v.end(), out);



}