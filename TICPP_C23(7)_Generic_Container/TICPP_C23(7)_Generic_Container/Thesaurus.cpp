#include "stdafx.h"
#include "Thesaurus.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef map<string, vector<string>> Thesaurus;
typedef pair<string, vector<string>> TEntry;
typedef Thesaurus::iterator TIter;

namespace std {
	ostream& operator<<(ostream & os, const TEntry& t)
	{
		os << t.first << ": ";
		copy(t.second.begin(), t.second.end(),ostream_iterator<string>(os, " "));
		return os;
	}
}

class ThesaurusGen
{
	static const string letters;
	static int count;
public:
	int maxSize() { return letters.size(); }
	TEntry operator()()
	{
		TEntry result;
		if (count >= maxSize()) count = 0;
		result.first = letters[count++];
		int entries = (rand() % 5) + 2;
		for (int i = 0;i<entries; i++)
		{
			int choice = rand() % maxSize();
			char cbuf[2] = { 0 };
			cbuf[0] = letters[choice];
			result.second.push_back(cbuf);
		}
		return result;
	}
};

int ThesaurusGen::count = 0;
const string ThesaurusGen::letters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

string menu(Thesaurus& thesaurus)
{
	while (true)
	{
		cout << "Select a \"word\", 0 to quit: ";
		for (TIter it = thesaurus.begin();
			it!= thesaurus.end(); it++ )
		{
			cout << (*it).first << ' ';
		}
		cout << endl;
		string reply;
		cin >> reply;
		if (reply.at(0) == '0') exit(0);
		if(thesaurus.find(reply) == thesaurus.end())
			continue;
		return reply;
	}
}


void Thesaurus_Test::Run()
{
	srand(time(0));
	Thesaurus thesaurus; 
	generate_n(inserter(thesaurus, thesaurus.begin()), 10, ThesaurusGen());
	copy(thesaurus.begin(), thesaurus.end(), ostream_iterator<TEntry>(cout, "\n") );
	cout << "------------------"<<endl;
	string keys[10];
	int i = 0;
	for (TIter it = thesaurus.begin();it!=thesaurus.end();it++)
	{
		keys[i++] = it->first;
	}
	for (int count = 0; count<10; count++)
	{
		string reply = keys[rand() % 10];
		vector<string>& v = thesaurus[reply];
		cout << reply << ":";
		copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}
}

