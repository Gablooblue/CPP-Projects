#include <iostream>
using namespace std;

int main()
{
	unsigned int primeNumber;
	bool divisible;

	for(int x = 2; x < 10000; x++)
	{
		divisible = false;
		for(int y = x - 1 ; y > 0; y--)
		{
			if(x % y == 0 && y != 1)
			{
				divisible = true;
				break;
			}
		}
		if(divisible == false)
		{
			cout << x << " ";
		}
	}
}

