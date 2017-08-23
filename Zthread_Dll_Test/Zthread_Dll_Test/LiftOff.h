#pragma once
#include <iostream>
#include <sstream>
#include "zthread/Runnable.h"
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread//ThreadedExecutor.h"

using namespace std;
using namespace ZThread;

class LiftOff_Disply
{
	Mutex iolock;
public:
	void Display(ostringstream& os)
	{
		Guard<Mutex> g(iolock);
		cout << os.str();
	}

};

class LiftOff :public ZThread::Runnable
{
	int countDown;
	int id;
	//Mutex lock;
	CountedPtr<LiftOff_Disply> display;
public:

	LiftOff(int count, CountedPtr<LiftOff_Disply>& disp, int ident = 0):countDown(count),id(ident),display(disp)
	{
	}

	~LiftOff()
	{
		ostringstream os;
		os << id << "completed" << std::endl;

	}
	void run()
	{
		//Guard<Mutex> g(lock);
		//lock.acquire();
		while (countDown--)
		{
			//Guard<Mutex, UnlockedScope> h(g);
			ostringstream os;
			os << id << ":"<< countDown <<"-"<< std::endl;
			display->Display(os);

		}
		//ostringstream os;
		//std::cout << "Liftoff!" << std::endl;
		//display->Display(os);
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
			CountedPtr<LiftOff_Disply> display(new LiftOff_Disply);
			const int SZ = 2;
			ThreadedExecutor executor;
			for (int i = 0; i<SZ;i++)
			{
				executor.execute(new LiftOff(10,  display,i));
				//Thread t(new LiftOff(10, display),i);

				//Thread t(new LiftOff(10, display), i);
			}
			cout << "Waiting for LiftOff" << endl;
		}
		catch (Synchronization_Exception& e)
		{
			cerr << e.what() << endl;
		}
	}
};

