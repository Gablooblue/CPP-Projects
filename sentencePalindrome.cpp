#include <iostream>
#include <string>

using namespace std;

#define STRING_START 0
#define SUCCEEDING_LETTER 1
#define PREVIOUS_LETTER -1

bool reverseString(string wordInput);

int main()
{
	int palindrome_count = 0, begin = 0, y, letters;
	bool result;
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
				begin = x + SUCCEEDING_LETTER;
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
	int letter_count = wordInput.length();
	int comparisons =  letter_count / 2;
	for(i = 0; i < comparisons; i++)
	{
		if(tolower(wordInput.at(i)) == tolower(wordInput.at( letter_count - i + PREVIOUS_LETTER )))
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
