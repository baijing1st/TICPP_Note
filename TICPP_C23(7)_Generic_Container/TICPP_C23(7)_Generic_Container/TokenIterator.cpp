#include "stdafx.h"
#include "TokenIterator.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include "require.h"

using namespace std;

void TokenIterator_Test::Run()
{
	char* fname = "TokenIterator.cpp";
	ifstream in(fname);
	assure(in, fname);
	ostream_iterator<string> out(cout, "\n");
	typedef istreambuf_iterator<char> IsbIt;
	IsbIt begin(in), isbEnd;
	Delimiters delimiters("\t\n~;()\"<>:{}[]+-=&*#.,/\\ ");
	TokenIterator<IsbIt, Delimiters> wordIter(begin, isbEnd, delimiters), end;
	vector<string> wordlist;
	copy(wordIter, end, back_inserter(wordlist));
	copy(wordlist.begin(), wordlist.end(),out);
	*out++ = "----------------------------------------";
	//Use a char array as the source
	char *cp = "typedef std::istreambuf_iterator<char> It";
	TokenIterator<char*, Delimiters> charIter(cp, cp+strlen(cp), delimiters), end2;
	vector<string> wordlist2;
	copy(charIter, end2, back_inserter(wordlist2));
	copy(wordlist2.begin(), wordlist2.end(), out);
	*out++ = "------------------------------------------";
	//Use a deque<char> as the source
	ifstream in2(fname);
	deque<char> dc;
	copy(IsbIt(in2), IsbIt(), back_inserter(dc));
	TokenIterator<deque<char>::iterator, Delimiters>
		dcIter(dc.begin(), dc.end(), delimiters), end3;
	vector<string> wordlist3;
	copy(dcIter, end3, back_inserter(wordlist3));
	//copy(dcIter->begin(), dcIter->end(), back_inserter(wordlist3));
	copy(wordlist3.begin(), wordlist3.end(), out);
	*out++ = "----------------------------------------------";
	//Reproduce the WordList.cpp example
	ifstream in3(fname);
	TokenIterator<IsbIt, Delimiters> wordIter2(IsbIt(in3), isbEnd, delimiters),end4;
	set<string> wordlist4;
	//copy(wordIter2, end4, back_inserter(wordlist4)); //set 没有push_back()函数所以不能在这儿这么用，只有insert

	while (wordIter2 != end)
	{
		wordlist4.insert(*wordIter2++);
	}
	copy(wordlist4.begin(), wordlist4.end(), out);


}