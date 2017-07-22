#include "stdafx.h"
#include "NoisyMap.h"
#include <map>
#include "Noisy.h"

using namespace std;


NoisyMap::NoisyMap()
{
}


NoisyMap::~NoisyMap()
{
}

void NoisyMap_Test::Run()
{
	{
		map<Noisy, Noisy> mnn;
		Noisy n1, n2;
		cout << "\n---------------" << endl;
		mnn[n1] = n2;
		cout << "\n---------------" << endl;
		cout << mnn[n1];
		cout << "\n----------------" << endl;
	}

}
