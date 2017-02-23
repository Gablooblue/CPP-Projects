#include <iostream>
#include <string>

using namespace std;

bool reverseString(string wordInput);

int main()
{
	int palindrome_count = 0, begin = 0, y, letters;
	bool result;
	int STRING_START = 0;
	int LETTER_AFTER = 1;
	string wordInput, word;

	cout << "Input a string here > ";
	getline(cin,wordInput);
	for(int x = 0; x < wordInput.length(); x++)
	{
		if(wordInput.at(x) == ' ' || x == STRING_START)
		{
			if(x == 0 && wordInput.at(STRING_START) != ' ')
			{
				begin = STRING_START;
			}
			else
			{
				begin = x + LETTER_AFTER;
			}
			letters = 0;
			for(y = begin; y < wordInput.length() && wordInput.at(y) != ' ' ; y++)
			{
				letters++;
			}
			word = wordInput.substr(begin, letters);
			if(reverseString(word) == true)
			{
				palindrome_count++;
			}
		}
	}
	cout << "There are " << palindrome_count << " palindromes";
}

bool reverseString(string wordInput)
{
	int i;
	int letters = wordInput.length();
	int comparisons = letters / 2;
	int PREVIOUS_LETTER = -1;
	for(i = 0; i < comparisons; i++)
	{
		if(tolower(wordInput.at(i)) == tolower(wordInput.at(letters + PREVIOUS_LETTER - i)))
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
