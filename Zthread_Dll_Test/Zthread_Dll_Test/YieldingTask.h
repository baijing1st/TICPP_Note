#pragma once
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"

using namespace ZThread;
using namespace std;
//using std::cout;
//using std::endl;



class YieldingTask: public Runnable
{
	int countDown;
	int id;
public:
	YieldingTask(int ident = 0) :countDown(5), id(ident) {}

	~YieldingTask()
	{
		cout << id << " completed" << endl;
	}

	friend ostream& operator<<(ostream& os, const YieldingTask&yt)
	{
		return os << "#" << yt.id << ":" << yt.countDown;
	}

	void run()
	{
		while (true)
		{
			cout << *this << endl;
			if (--countDown == 0)
			{
				return;
			}
			Thread::yield();
		}
	}
};

class YieldingTask_Test
{
public:
	void Run()
	{
		try
		{
			ThreadedExecutor executor;
			for (int i = 0; i<5; i++)
			{
				executor.execute(new YieldingTask(i));
			}
		}
		catch (Synchronization_Exception& e)
		{
			cerr << e.what() << endl;
		}
	}

};

