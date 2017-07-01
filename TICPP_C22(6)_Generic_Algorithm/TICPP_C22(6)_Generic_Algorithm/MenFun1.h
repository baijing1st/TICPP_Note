#pragma once
#include<algorithm>
#include <functional>
#include <iostream>
#include <vector>

class Shape
{
public:
	virtual void Draw() = 0;
	virtual  ~Shape() {};
};

class Circle :public Shape
{
public:
	virtual void Draw();
	~Circle();
};

class Square :public Shape
{
public:
	virtual void Draw();
	~Square();
};



class MenFun1_Test
{
public:
	void Run();
};

