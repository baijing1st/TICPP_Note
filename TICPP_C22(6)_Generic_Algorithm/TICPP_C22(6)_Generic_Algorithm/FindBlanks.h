#pragma once
#include <algorithm>
#include <functional>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
#include "require.h"

typedef std::vector<std::string>::iterator LSI;

class FindBlanks
{
public:
	FindBlanks();
	~FindBlanks();
};

class FindBlanks_Test
{
public:
	void Run()
	{
		std::string ssss(5,' ');
		char* fname = "FindBlanks.h";
		std::ifstream in(fname);
		assure(in, fname);
		std::vector<std::string> vs;
		std::string s;
		while (getline(in,s))
		{
			vs.push_back(s);
		}
		std::vector<std::string> cpy = vs;
		LSI lsi = std::find_if(vs.begin(), vs.end(), mem_fun_ref(&std::string::empty));
		while (lsi!=vs.end())
		{
			*lsi = "A BLANK LINE";
			lsi = find_if(vs.begin(), vs.end(), mem_fun_ref(&std::string::empty));

		}
		for (size_t i = 0; i < cpy.size();i++)
		{
			if (cpy[i].size() == 0)
			{
				assert(vs[i] == "A BLANK LINE");
			} 
			else
			{
				assert(vs[i] != "A BLANK LINE");
			}
		}
	}
};

