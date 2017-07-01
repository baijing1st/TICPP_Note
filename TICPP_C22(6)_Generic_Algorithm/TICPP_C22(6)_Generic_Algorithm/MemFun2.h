#pragma once
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

class Angle
{
	int degrees;
public:Angle(int deg) :degrees(deg) {}
	   int mul(int times) { return degrees *= times; }
};

class MemFun2
{
public:
	MemFun2();
	~MemFun2();
};

class MemFun2_Test
{
public:
	void Run()
	{
		std::vector<Angle> va;
		for (int i=0;i<50;i+=10)
		{
			va.push_back(Angle(i));
		}
		int x[] = { 1,2,3,4,5 };
		std::transform(va.begin(), va.end(), x,
			std::ostream_iterator<int>(std::cout, " "),
			std::mem_fun_ref(&Angle::mul));
		std::cout << std::endl;
	}
};

