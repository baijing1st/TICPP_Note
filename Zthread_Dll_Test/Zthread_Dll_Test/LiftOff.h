#pragma once
#include <iostream>
#include "zthread/Runnable.h"
#include "zthread/Thread.h"

using namespace std;
using namespace ZThread;

class LiftOff :public ZThread::Runnable
{
	int countDown;
	int id;
public:

	LiftOff(int count,int ident = 0):countDown(count),id(ident)
	{
	}

	~LiftOff()
	{
		std::cout << id << "completed" << std::endl;
	}
	void run()
	{
		while (countDown--)
		{
			std::cout << id << ":"<< countDown << std::endl;
		}
		std::cout << "Liftoff!" << std::endl;
	}
};

class LiftOff_Test
{
public:
	void Run()
	{
		try
		{
			Thread t(new LiftOff(10)   );
			cout << "Waiting for LiftOff" << endl;
		}
		catch (Synchronization_Exception& e)
		{
			cerr << e.what() << endl;
		}
	}
};

