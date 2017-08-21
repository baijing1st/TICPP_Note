#pragma once
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Cancelable.h"
#include "zthread/ThreadLocal.h"
#include "zthread/CountedPtr.h"
using namespace std;
using namespace ZThread;

class ThreadLocalVariables:public Cancelable
{
	ThreadLocal<int> value;
	bool canceled;
	Mutex lock;
public:

	ThreadLocalVariables():canceled(false)
	{
		value.set(0);
	}

	void increment() { value.set(value.get() + 1); }

	int get() { return value.get(); }

	void cancel() 
	{
		Guard<Mutex> g(lock); 
		canceled = true;
	}

	bool isCanceled()
	{
		Guard<Mutex> g(lock);
		return canceled;
	}

	~ThreadLocalVariables(){}
};

class Accessor :public Runnable
{
	int id;
	CountedPtr<ThreadLocalVariables> tlv;
public:
	Accessor(CountedPtr<ThreadLocalVariables>& tl, int idn)
		:id(idn), tlv(tl) {}

	void run()
	{
		while (!tlv->isCanceled())
		{
			tlv->increment();
			cout << *this << endl;
		}
	}

	friend ostream& operator<<(ostream& os, Accessor& a)
	{
		return os << "#" << a.id << ": " << a.tlv->get();
	}
};

class ThreadLocalVariables_Test
{
public:
	int Run()
	{
		cout << "Press ctl - c to quit" << endl;
		try
		{
			CountedPtr<ThreadLocalVariables> tlv(new ThreadLocalVariables);
			const int sz = 5;
			ThreadedExecutor executor;
			for (int i = 0; i<sz; i++)
			{
				executor.execute(new Accessor(tlv, i) );
			}
			cin.get();
			tlv->cancel();
		}
		catch (Synchronization_Exception& e)
		{
			cerr << e.what() << endl;
		}
		return 0;
	}
};

