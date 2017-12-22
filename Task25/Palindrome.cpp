#include "Palindrome.h"
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;


T_Palindrom::T_Palindrom(string s) : str(s)
{
	make_palindrom();
};

void T_Palindrom::getInput()
{
	cout << "Enter string: " << endl;
	cin >> str;
	make_palindrom();
};


string T_Palindrom::remove_wrong_symbols(int left, int right)
{
	if (right - left == 0)
		return "";
	else if (right - left == 1)
	{
		string s = "";
		s.push_back(str[left]);
		return s;
	}

	map<pair<int, int>, string>::iterator it = hash.find({ left, right });
	if (it != hash.end())
		return it->second;
	
	if (str[left] == str[right - 1])
	{
		string x = str[left] + remove_wrong_symbols(left + 1, right - 1) + str[right - 1];
		hash.insert({ { left, right }, x });
		return x;
	}
		
	string x1 = remove_wrong_symbols(left + 1, right);


	string x2 = remove_wrong_symbols(left, right - 1);
	
	
	string x3 = remove_wrong_symbols(left + 1, right - 1);
	
	
	if (x1.size() >= x2.size())
		if (x1.size() >= x3.size())
		{
			hash.insert({ { left, right }, x1 });
			return x1;
		}
		else
		{
			hash.insert({ { left, right }, x3 });
			return x3;
		}
	else if (x2.size() >= x3.size())
	{
		hash.insert({ { left, right }, x2 });
		return x2;
	}
	else
	{
		hash.insert({ { left, right }, x3 });
		return x3;
	}
}

void T_Palindrom::make_palindrom()
{
	str = remove_wrong_symbols(0, str.size());
	hash.clear();
}