#include <iostream>
#include <string>

using namespace std;

bool reverseString(string wordInput);

int main()
{
	int palindromeCount = 0, begin = 0, y, letCount;
	bool result;
	string wordInput, word;

	cout << "Input a string here > ";
	getline(cin,wordInput);
	for(int x = 0; x < wordInput.length(); x++)
	{
		if(wordInput.at(x) == ' ' || x == 0)
		{
			if(x == 0 && wordInput.at(0) != ' ')
			{
				begin = 0;
			}
			else
			{
				begin = x + 1;
			}
			letCount = 0;
			for(y = begin; y < wordInput.length() && wordInput.at(y) != ' ' ; y++)
			{
				letCount++;
			}
			word = wordInput.substr(begin, letCount);
			if(reverseString(word) == true)
			{
				palindromeCount++;
			}
		}
	}
	cout << "There are " << palindromeCount << " palindromes";
}

bool reverseString(string wordInput)
{
	string reverse;
	int index;
	int letCount = wordInput.length();
	int compCount = letCount / 2;
	for(index = 0; index < compCount; index++)
	{
		if(wordInput.at(index) == wordInput.at(letCount - 1 - index))
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
