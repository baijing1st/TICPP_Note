#include "stdafx.h"
#include "WordList.h"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include "require.h"
using namespace std;

char replaceJunk(char c)
{
	return (isalpha(c) || c == '\'') ? c : ' ';
}


WordList::WordList()
{
}


WordList::~WordList()
{
}

void WordList_Test::Run()
{
	char * fname = "WordList.cpp";
	ifstream in(fname);
	assure(in, fname);
	set<string> wordlist;
	string line;
	while (getline(in, line))
	{
		transform(line.begin(), line.end(), line.begin(), replaceJunk);
		istringstream is(line);
		string word;
		while (is >> word)
		{
			wordlist.insert(word);
		}
	}
	copy(wordlist.begin(), wordlist.end(), ostream_iterator<string>(cout, "\n"));
}
