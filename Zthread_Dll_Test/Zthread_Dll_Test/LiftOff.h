#pragma once
#include <iostream>
#include "zthread/Runnable.h"
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"

using namespace std;
using namespace ZThread;

class LiftOff :public ZThread::Runnable
{
	int countDown;
	int id;
	Mutex lock;
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
		Guard<Mutex> g(lock);
		//lock.acquire();
		while (countDown--)
		{
			Guard<Mutex, UnlockedScope> h(g);
			std::cout << id << ":"<< countDown <<"-"<< std::endl;
		}
		std::cout << "Liftoff!" << std::endl;
		//lock.release();
	}
};

class LiftOff_Test
{
public:
	void Run()
	{
		try
		{
			const int SZ = 2;
			for (int i = 0; i<SZ;i++)
			{
				Thread t(new LiftOff(10),i);
			}
			cout << "Waiting for LiftOff" << endl;
		}
		catch (Synchronization_Exception& e)
		{
			cerr << e.what() << endl;
		}
	}
};

