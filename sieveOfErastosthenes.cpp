#include <iostream>
#include <cmath>

using namespace std;

#define FIRST_PRIME 2
#define DIVISIBLE 0

int main()
{
    int maximum, upper_bound;

    cout << "Input an integer> "; 
    cin >> maximum;
    int numbers[maximum];

    cout << "Printing all prime numbers from 1 to " << maximum << endl;

    for(int i = 0; i < maximum; i++)
    {
	numbers[i] = i;
    }	

    for(int i = FIRST_PRIME; i < maximum; i++)
    {
	/**This is based on a specific concept of prime numbers
	 * stating that a number is prime if it is indivisible
	 * by every discrete number until the floor function of the number's
	 * square root
	 * 
	 * So here we set the upper_bound to the floor of the current
	 * number's square root
	*/
	upper_bound = sqrt(i);

	for(int j = FIRST_PRIME; j <= upper_bound; j++)
	{
	    if(i % j == DIVISIBLE)
	    {
		//changes value to zero
		numbers[i] = 0;
		break;
	    }	
	}

	if(numbers[i] != DIVISIBLE)
	{
	    cout << numbers[i] << " ";
	}    
    }	
    cout << endl;

} 
