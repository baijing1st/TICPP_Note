#include "stdafx.h"
#include "AssocInserter.h"

using namespace std;
AssocInserter::AssocInserter()
{
}


AssocInserter::~AssocInserter()
{
}

void AssocInserter_Test::Run()
{
	set<int> s;
	fill_n(inserter(s, s.begin()), 10, 47); //Æ«ÒÆ10
	generate_n(inserter(s, s.begin()), 10, IncrGen<int>(12));
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, "\n"));
	map<int,int> m;
	cout << endl;
	fill_n( inserter(m, m.begin()), 10, make_pair(90, 120));
	generate_n(inserter(m, m.begin()), 10, PairGen<int,int>(3,9));
	copy(m.begin(), m.end(), ostream_iterator<pair<int,int>>(cout, "\n"));

}

