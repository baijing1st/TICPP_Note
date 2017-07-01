#include "stdafx.h"
#include "MenFun1.h"

using namespace std;

void Circle::Draw()
{
	cout << "Circle::Draw()" << endl;
 }

Circle::~Circle()
{
	cout << "Circle::~Circle()" << endl;
}



void Square::Draw()
{
	cout << "Square::Draw()" << endl;

}


Square::~Square()
{
	cout << "Square::~Circle()" << endl;
}


void MenFun1_Test::Run()
{
	vector<Shape*> vs;
	vs.push_back(new Circle());
	vs.push_back(new Square());
	for_each(vs.begin(), vs.end(), mem_fun(&Shape::Draw));
}



