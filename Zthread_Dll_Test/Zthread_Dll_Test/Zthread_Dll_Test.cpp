// Zthread_Dll_Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "LiftOff.h"
#include "ResponsiveUI.h"
#include "PoolExccutor_Example.h"
#include "ConcurrentExecutor_Example.h"
#include "YieldingTask.h"
#include "SimplePriorities.h"
#include "ThreadLocalVariables.h"


int main()
{
	//LiftOff_Test lt;
	//lt.Run();

	//ResponsiveUI_Test rt;
	//rt.Run();

	//PoolExccutor_Test pt;
	//pt.Run();

	//ConcurrentExecutor_Test ct;
	//ct.Run();

	//YieldingTask_Test yt;
	//yt.Run();

	//SimplePriorities_Test st;
	//st.Run();

	ThreadLocalVariables_Test tvt;
	tvt.Run();

	getchar();
    return 0;
}

