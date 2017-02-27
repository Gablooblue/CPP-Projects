#include "OrderedPair.h"
#include <iostream>
#include <string>

using namespace std;

string *CartesianProduct(string first[], int first_len, string second[], int sec_len, string result[], int pair_num);

int main()
{
	int first_len, sec_len, pair_num ;

	//Asks how many elements in each group
	cout << "How many elements in first? ";
	cin >> first_len;
	cout << "How many elements in second?";
	cin >> sec_len;

	//Sets arrays for everything
	/**
	 * pair_num gets number of pairs possible by multiplying the
	 * 	cardinality of first and second sets
	 */
	pair_num = first_len * sec_len;
	//Creates results element
	string result[pair_num];
	//A pointer which will point to the result array later on
	string *pairs;
	//Of course the arrays for first and second sets
	string first[first_len], second[sec_len];


	//Input numbers 
	for(int i = 0; i < first_len; i++)
	{
		cout << "Input an element in first group: ";
		cin >> first[i];
	}
	for(int i = 0; i < sec_len; i++)
	{
		cout << "Input an element in the second group: ";
		cin >> second[i];
	}

	//calls Cartesian Product function 
	pairs = CartesianProduct(first, first_len, second, sec_len, result, pair_num);

	//prints out all the pairs
	for(int i = 0; i < pair_num; i++)
	{
		cout << pairs[i] << endl;
	}
}

/**
 * @params first array and cardinality,
 * 	second array and cardinality,
 * 		result array and cardinality
 *
 * @return pointer that points to the address of the result array
 */
string *CartesianProduct(string first[], int first_len, string second[], int sec_len, string result[], int pair_num)
{
	//This index is incremented to put values in every element of the array
	int arr_index = 0;

	// pointer string that points to the result array
	string *pointer; 
	pointer = result;

	for(int i = 0; i < first_len; i++)
	{
		for(int j = 0; j < sec_len; j++)
		{
			result[arr_index]  = "(" + first[i] + ", " + second[j] + ")";
			arr_index++;
		}
	}
	return pointer;
}
