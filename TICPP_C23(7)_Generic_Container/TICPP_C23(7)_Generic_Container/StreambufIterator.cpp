#include "stdafx.h"
#include "StreambufIterator.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "require.h"
using namespace std;

StreambufIterator::StreambufIterator()
{
}


StreambufIterator::~StreambufIterator()
{
}

void StreambufIterator_Test::Run()
{
	ifstream in("StreambufIterator.cpp");
	assure(in, "StreambufIterator.cpp");

	istreambuf_iterator<char> isb(in), end;
	ostreambuf_iterator<char> osb(cout);
	while (isb != end)
		*osb++ = *isb++;
	cout << endl;
	ifstream in2("StreambufIterator.cpp");
	istream_iterator<char> is(in2), end2;
	ostream_iterator<char> os(cout);
	while (is != end2)
		*os++ = *is++;
	cout << endl;
}