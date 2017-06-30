// TICPP_C22(6)_Generic_Algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CopyInts.h"
#include "FBinder.h"
#include "CopyInts2.h"
#include "CopyInts4.h"

int main()
{
	CopyInts_Test ct;
	ct.Run();
	//getchar();

	FBinder_Test fbt;
	fbt.Run();
	//CopyInts_Test cit;
	//cit.Run();

	//CopyInts2_Test ci2t;
	//ci2t.Run();

	CopyInts4_Test ci4t;
	ci4t.Run();

	getchar();

    return 0;
}

