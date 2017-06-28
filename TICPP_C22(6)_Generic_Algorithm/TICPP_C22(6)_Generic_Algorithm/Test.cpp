#include "stdafx.h"
#include <iostream>
#include <typeinfo>
#include "Test.h"
using namespace std;

namespace TestSuite {

	void Test::do_test(bool cond, const string & lbl, const char* fname, long lineno)
	{
		if (!cond)
		{
			do_fail(lbl, fname, lineno);
		}
		else
		{
			succeed_();
		}
	}

	void Test::do_fail(const string& lbl, const char* fname, long lineno)
	{
		++nFail;
		if (osptr)
		{
			if (1 == nFail)
			{
				*osptr << typeid(*this).name() <<endl
					<< "\tFailure " << nFail
					<< ": (" << lbl << ")"
					<< "\n\t\tFile: " << fname
					<< "\n\t\tLine: " << lineno << endl;
			} 
			else
			{
				*osptr <<"\tFailure " << nFail
					<< ": (" << lbl << ")"
					<< "\n\t\tFile: " << fname
					<< "\n\t\tLine: " << lineno << endl;
			}
			
		}
	}

	long Test::report() const
	{
		if (osptr)
		{
			*osptr << "Test \"" << typeid(*this).name()
				<< "\":\n\tPassed: " << nPass
				<< "\tFailed:" << nFail
				<< endl;
		}
		return nFail;
	}
			
}
