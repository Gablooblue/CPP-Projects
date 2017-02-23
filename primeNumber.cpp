#include <iostream>

using namespace std;

#define UPPER_LIMIT 10000
int main()
{
	unsigned int primeNumber, previous_number;
	bool divisible;

	for(int i = 2; i < UPPER_LIMIT; i++)
	{
		divisible = false;
		previous_number = i - 1;
		for(int j = previous_number ; j > 0; j--)
		{
			if(i % j == 0 && j != 1)
			{
				divisible = true;
				break;
			}
		}
		if(divisible == false)
		{
			cout << i << " ";
		}
	}
}

