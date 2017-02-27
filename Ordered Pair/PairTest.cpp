#include "OrderedPair.h"
#include <iostream>
#include <string>

using namespace std;

/** 
 * @param first, second, pairs 
 * @return pairs 
 */
OrderedPair OrderedPair::getPairs(string first[], int first_len, string second[], int sec_len, OrderedPair pairs[],int pair_num)
{
	//I used arr_index because i couldn't figure out how to pass 2d arrays
	//If ur mad then bite me
	int arr_index = 0;
	//Gets all possible pairs
	for(int i = 0; i < first_len; i++)	
	{
		for(int j = 0; j < sec_len; j++)
		{
			//setting object values
			pairs[arr_index].first = first[i];
			pairs[arr_index].second = second[j];
			arr_index++;
		}	
	}	
}	

int main()
{
	int first_len, sec_len, pair_num, arr_index; 

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

	//Creating a pairs object 
	OrderedPair pairs[pair_num];

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

	pairs[pair_num].getPairs(first, first_len, second, sec_len, pairs, pair_num);
	//prints out all pairs
	for(int i = 0; i < pair_num; i++)
	{
		cout << '('
		     << pairs[i].first
		     << ','
		     << pairs[i].second
		     << ')'
		     << " ";
	}	
}


