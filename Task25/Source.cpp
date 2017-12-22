//From given line, delete the smallest number of characters, so that it turns out to be a palindrome 
//(palindrome is a line that is equally readable from right to left, and from left to right).


#include <iostream>
#include "Palindrome.h"

using namespace std;

int main()
{
	T_Palindrom palindrom;
	palindrom.getInput();
	cout << palindrom.str;
	system("pause");
	return 0;
}