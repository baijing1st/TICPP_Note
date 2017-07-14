#pragma once
#include <algorithm>
#include <cctype>
#include <functional>
#include <iterator>
#include <string>

struct  Isalpha: std::unary_function<char,bool>
{
	bool operator()(char c) { return std::isalpha(c); }
};

class Delimiters : std::unary_function<char, bool>
{
	std::string exclude;
public:
	Delimiters() {}
	Delimiters(const std::string &excl):exclude(excl){}
	bool operator()(char c)
	{
		return exclude.find(c) == std::string::npos;
	}
};

template<class InputIter, class Pred = Isalpha>
class TokenIterator 
	: public std::iterator<std::input_iterator_tag,std::string, std::ptrdiff_t>
{
	InputIter first;
	InputIter last;
	std::string word;
	Pred predicate;

public:
	TokenIterator(InputIter begin, InputIter end, Pred pred = Pred())
		:first(begin), last(end), predicate(pred) {
		++*this;
	}

	TokenIterator() {}	//End Sentinel

	TokenIterator& operator++()//prefix increment
	{
		word.resize(0);
		first = std::find_if(first, last, predicate);
		while (first!=last && predicate(*first))
		{
			word += *first++;
		}
		return *this;
	}
	class CaptureState
	{
		std::string word;
	public:
		CaptureState(const std::string&w):word(w){}
		std::string operator*() { return word; }
	};
	CaptureState operator++(int) //postfix increment
	{
		CaptureState d(word);
		++*this;
		return d;
	}

	std::string operator*() const { return word; }
	const std::string* operator->() const { return &word; }
	bool operator == (const TokenIterator&)
	{
		return word.size() == 0 && first == last;
	}
	bool operator!=(const TokenIterator& rv)
	{
		return !(*this == rv);
	}
};

class TokenIterator_Test
{
public:
	void Run();
};

