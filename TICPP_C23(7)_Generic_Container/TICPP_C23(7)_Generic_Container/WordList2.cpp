#include "stdafx.h"
#include "WordList2.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <algorithm>
#include "require.h"
using namespace std;

WordList2::WordList2()
{
}


WordList2::~WordList2()
{
}


void WordList2_Test::Run()
{
	char *fname = "WordList2.cpp";
	ifstream in(fname);
	assure(in, fname);
	istreambuf_iterator<char> p(in), end;
	set<string> wordlist;
	while (p!=end)
	{
		string word;
		insert_iterator<string> ii(word, word.begin());
		while (p!=end&&!isalpha(*p))
		{
			++p;
		}
		while (p!=end&&isalpha(*p))
		{
			*ii++ = *p++;
		}
		if (word.size()!=0)
		{
			wordlist.insert(word);
		}
	}
	copy(wordlist.begin(), wordlist.end(), ostream_iterator<string>(cout, "\n"));
}
