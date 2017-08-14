#include "stdafx.h"
#include "Stlshape2.h"
#include <iostream>
#include <vector>
#include "purge.h"

using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Circle : public Shape
{
public:
	Circle() { cout << "Circle()" << endl; }
	~Circle() { cout << "~Circle()" << endl; }
	void draw() { cout << "Circle::Draw()" << endl; }
};

class Square : public Shape
{
public:
	Square() { cout << "Square()" << endl; }
	~Square() { cout << "~Square()" << endl; }
	void draw() { cout << "Square::Draw()"<<endl; }
};

template<class T>
class Draw
{
public:
	Draw()  {}
	void operator()( T * ss)
	{
		ss->draw();
	}

};


void Stlshape2_Test::Run()
{
	typedef vector<Shape*> Container;
	typedef Container::iterator Iter;
	Container shapes;
	shapes.push_back(new Circle());
	shapes.push_back(new Square());
	shapes.push_back(new Circle());
	for_each(shapes.begin(), shapes.end(), Draw<Shape>());
	//purge(shapes);
	purge(shapes.begin(), shapes.end());
}



