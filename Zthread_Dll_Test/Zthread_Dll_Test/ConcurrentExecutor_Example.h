#pragma once
#include <iostream>
#include "zthread/ConcurrentExecutor.h"
#include "LiftOff.h"

class ConcurrentExecutor_Test
{
public:
public:
	void Run()
	{
		try
		{
			ConcurrentExecutor excutor;
			//ConcurrentExecutor excutor2;
			for (int i = 0; i < 5; i++)
			{
//				excutor.execute(new LiftOff(10, i));
				//excutor2.execute(new LiftOff(10, i));
			}
		}
		catch (Synchronization_Exception& e)
		{
			cerr << e.what() << endl;
		}
	}
};

