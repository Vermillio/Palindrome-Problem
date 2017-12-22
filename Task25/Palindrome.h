#pragma once;
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class T_Palindrom
{
private:
	map<pair<int, int>, string> hash;
	string remove_wrong_symbols(int left, int right);
	void make_palindrom();
public:
	string str;

	void getInput();
	T_Palindrom() {};
	T_Palindrom(string s);
};