#pragma once
#include <iostream>
#include "zthread/PoolExecutor.h"
#include "LiftOff.h"

using namespace std;
using namespace ZThread;

class PoolExccutor_Test
{
public:
	void Run()
	{
		try
		{
			PoolExecutor excutor(2);
			for (int i = 0; i<5; i++)
			{
//				excutor.execute(new LiftOff(10, i));
			}
		}
		catch (Synchronization_Exception& e)
		{
			cerr << e.what() << endl;
		}
	}
};

