#include "stdafx.h"
#include "StreamIt.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "require.h"
using namespace std;



StreamIt::StreamIt()
{
}


StreamIt::~StreamIt()
{
}

void StreamIt_Test::Run()
{
	ifstream in("StreamIt.cpp");
	assure(in, "StreamIt.cpp");
	istream_iterator<string> begin(in), end;
	ostream_iterator<string> out(cout, "\n");
	vector<string> vs;
	copy(begin, end, back_inserter(vs));
	copy(vs.begin(), vs.end(), out);
	*out++ = vs[0];
	*out++ = "That's all, folks!";

}
