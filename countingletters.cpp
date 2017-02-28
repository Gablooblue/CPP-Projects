#include <iostream>
#include <fstream>
#include <string>

#define ASCII_LOWERCASE 49
#define ASCII_UPPERCASE 17
#define LETTERS_IN_ALPHABET 26

using namespace std;

void printFile(int letter_count[], int letters);
void CountLetters(string filename);

int main()
{
	string file_input;
	cout << "Input filename: ";
	cin >> file_input;
	CountLetters(file_input);

	return 0;
}

void CountLetters(string filename)
{
	char letter;
	int letter_count[LETTERS_IN_ALPHABET], letter_ascii;
	//Opens file based on filename
	ifstream file(filename.c_str(), ios::in);

	//Setting values to 0
	for(int i = 0; i < LETTERS_IN_ALPHABET; i++)
	{
		letter_count[i] = 0;
	}	
	//If file fails to open
	if(!file)
	{
		cout << "Open file failed";
	}	
	//Checks all letters of file
	while(file >> letter)
	{
		//Gets the letter's ascii value and reduces it 
		//Doing this makes a = 0, b = 1, and so on
		letter_ascii = tolower(letter) - '0' - ASCII_LOWERCASE;

		//Checks if the value is a letter
		if(letter_ascii >= 0 && letter_ascii < 26)
		{	
			//Increments the values of the specific letter
			letter_count[letter_ascii]++;
		}
	}	

	//calls another function to print to file
	printFile(letter_count, LETTERS_IN_ALPHABET);
}	

void printFile(int letter_count[], int letters)
{
	ofstream file("letcountfile.txt", ios::out);

	char letter;
	//Iterates through all letters in alphabet
	for(int i = 0; i < LETTERS_IN_ALPHABET; i++)	
	{
		//Turns i into uppercase ASCII letters
		letter = (i + ASCII_UPPERCASE) + '0';

		//Prints the letters into the file
		file << letter << ":" << letter_count [i] << ' ';
	}	
}	


