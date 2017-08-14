#pragma once
#include <algorithm>


template<class Seq> void purge(Seq & c)
{
	typename Seq::iterator it;
	for (it = c.begin();it!=c.end();it++)
	{
		delete *it;
		*it = NULL;
	}
}

template<class InpIt> void purge(InpIt begin, InpIt end)
{
	while (begin!=end)
	{
		delete *begin;
		*begin = NULL;
		++begin;
	}
}


