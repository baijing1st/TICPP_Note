#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "zthread/Thread.h"

using namespace ZThread;
using namespace std;

class ResponsiveDisplayTask: public Runnable
{
	ifstream in;
	string line;
	bool quitFlag;
public:
	ResponsiveDisplayTask(const string &file):quitFlag(false)
	{
		in.open(file.c_str());
	}

	~ResponsiveDisplayTask(){in.close();	}

	void run()
	{
		while (getline(in, line) && !quitFlag)
		{
			cout << line << endl;
			Thread::sleep(1000);
		}
	}

	void quit() { quitFlag = true; }
};

class ResponsiveUI_Test
{
public:
	void Run()
	{
		try
		{
			cout << "Press<Enter> to quit:" << endl;
			ResponsiveDisplayTask * dt = new ResponsiveDisplayTask("ResponsiveUI.h");
			Thread t(dt);
			cin.get();
			dt->quit();
		}
		catch (Synchronization_Exception& e)
		{
			cerr << e.what() << endl;

		}
		cout << "Shutting Down..." << endl;
	}
};

