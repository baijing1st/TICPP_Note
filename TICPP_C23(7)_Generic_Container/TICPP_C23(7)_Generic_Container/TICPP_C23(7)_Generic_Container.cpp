// TICPP_C23(7)_Generic_Container.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Inserters.h"
#include "StreamIt.h"
#include "StreambufIterator.h"
#include "BasicSequenceOperations.h"
#include "VectorOverflow.h"

int main()
{
	//Inserters_Test ist;
	//ist.Run();

	//StreamIt_Test sit;
	//sit.Run();

	//StreambufIterator_Test sbit;
	//sbit.Run();

	//BasicSequenceOperations_Test bsot;
	//bsot.Run();

	VectorOverflow_Test voft;
	voft.Run();

	getchar();
    return 0;
}

