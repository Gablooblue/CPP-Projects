#include <iostream>
using namespace std;

int reverseNumber(int number);

int main()
{	
	int number, reverse;
	cout<< "Please input a number: ";
	cin >> number;
	reverse = reverseNumber(number);
	if (number == reverse)
	{
		cout << "Palindrome";
	}	
	else 
	{
		cout << "Not a palindrome";
	}	
}

int reverseNumber(int number)
{
	int reverse = 0;

	for (int x = 0; x < 5; x++)	
	{
		reverse = (reverse * 10) + (number  % 10);
		number /= 10;
	}		
	return reverse;
}	


