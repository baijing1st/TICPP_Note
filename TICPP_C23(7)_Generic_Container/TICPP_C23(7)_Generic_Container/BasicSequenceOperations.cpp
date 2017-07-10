#include "stdafx.h"
#include "BasicSequenceOperations.h"
#include <vector>
#include <deque>
#include <iostream>
#include <list>
using namespace  std;

template<typename Container>
void print(Container &c, char* title = "")
{
	std::cout << title << ":" << std::endl;
	if (c.empty())
	{
		std::cout << "(empty)" << std::endl << std::endl;
		return;
	}
	typename Container::iterator it;
	for (it = c.begin();it != c.end();it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "size()=" << c.size()
		<< ", max_size()=" << c.max_size()
		<< ", front()=" << c.front()
		<< ", back=" << c.back()
		<< std::endl<<std::endl;
}

template<typename ContainerofInt> 
void basicOps(char* s)
{
	cout << "----------" << s << "----------"<<endl;
	typedef ContainerofInt Ci;
	Ci c;
	print(c, "c after default constructor");
	Ci c2(10,1);
	print(c2, "c2 after constructor(10,1)");
	int ia[] = { 1,3,5,7,9 };
	const int iasz = sizeof(ia) / sizeof(*ia);
	Ci c3(ia, ia + iasz);
	print(c3, "c3 after constructor(iter,iter)");
	Ci c4(c3);
	print(c4, "c4 after copy_constructor(c2)");
	c = c2;
	print(c, "c after operator = c2");
	c.assign(ia, ia + iasz);
	print(c, "c after assign(iter,iter2)");
	std::cout << "c using reverse iterator:" << std::endl;
	typename Ci::reverse_iterator rit = c.rbegin();
	while (rit!= c.rend())
	{
		std::cout << *rit++ << " ";
	}
	std::cout << std::endl << std::endl;
	c.resize(4);
	print(c, "c after resize(4)");
	c.push_back(47);
	print(c, "c after push_back(47)");
	c.pop_back();
	print(c, "c after pop_back()");
	typename Ci::iterator it = c.begin();
	++it;++it;--it;
	c.insert(it, 74);
	print(c, "c after insert(it,74)");
	it = c.begin();
	++it;
	c.insert(it, 3, 96);
	print(c, "c insert(it,3,96)");
	it = c.begin();
	++it;
	c.insert(it, c3.begin(), c3.end());
	print(c, "c after insert(it,c3.begin(),c3.end()");
	it = c.begin();
	++it;
	c.erase(it);
	print(c, "c after erase(it)");
	typename Ci::iterator it2 = it = c.begin();
	++it;
	++it2;++it2; ++it2; ++it2; ++it2;
		c.erase(it, it2);
	print(c, "c after erase(it,it2)");
	c.swap(c2);
	print(c, "c after swap(c2)");
	c.clear();
	print(c, "c after clear()");

}

BasicSequenceOperations::BasicSequenceOperations()
{
}


BasicSequenceOperations::~BasicSequenceOperations()
{
}

void BasicSequenceOperations_Test::Run()
{
	basicOps<vector<int>>("vector");
	//basicOps<list<int>>("list");
}

