#pragma once
#include <cassert>
#include <cstdlib>
#include <functional>
#include<iostream>
#include<string.h>
#include <vector>
#include <algorithm>
#include <iterator>
class ComposeTry
{
public:
	ComposeTry();
	~ComposeTry();
};

template<typename R,typename E,typename F1,typename F2>
class unary_composer
{
	F1 f1;
	F2 f2;
public:
	unary_composer(F1 fone, F2 ftwo) :f1(fone), f2(ftwo) {}
	R operator()(E x) { return f1(f2(x)); }
};

template<typename R, typename E, typename F1, typename F2>
unary_composer<R, E, F1, F2> composer(F1 f1, F2 f2)
{
	return unary_composer<R, E, F1, F2>(f1, f2);
}

class ComposeTry_Test
{
public:
	void Run()
	{
		double x = composer<double, const std::string&>(atof, mem_fun_ref(&std::string::c_str))("12.34");
		assert(x == 12.34);

		std::vector<std::string> vs;
		vs.push_back("12.34");
		vs.push_back("56.78");
		vs.push_back("1.19");
		std::vector<double> vd;
		std::vector<std::string>::iterator ls = vs.begin();
		
		std::transform(vs.begin(), vs.end(), std::back_inserter(vd), composer<double, const std::string&>(atof, mem_fun_ref(&std::string::c_str)));
		int a = 10;
	}
};
