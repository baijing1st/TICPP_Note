#include "stdafx.h"
#include "FillGenerateTest.h"
#include <vector>
#include <algorithm>
#include <string>
#include "Generators.h"
#include "PrintSequence.h"

using namespace std;

void FillGenerate_Test::Run()
{
	vector<string> v1(5);
	fill(v1.begin(), v1.end(), "howdy");
	print(v1.begin(), v1.end(), "v1", " ");

}



