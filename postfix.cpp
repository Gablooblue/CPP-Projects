#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getWeight(char value);

int main()
{
    string equation;
    char temp;
    int weight;

    //used stack library because I got lazy
    stack<char> expressions;

    cout << "Input an equation> ";
    getline(cin,equation);

    for(int i = 0; i < equation.length(); i++)
    {
	weight = getWeight(equation[i]);

	if(weight == 0)
	{
	    cout << equation[i];
	}
	else if(weight == 1)
	{
	    if(!expressions.empty())
	    {
		temp = expressions.top();
		while(temp != '('  && !expressions.empty())
		{
		    cout << temp;
		    expressions.pop();
		    temp = expressions.top();
		}
		expressions.pop();
	    }
	}
	else if(weight == 2)
	{
	    expressions.push(equation[i]);
	}
	else if (weight == 3)
	{
	    if(!expressions.empty())
	    {
		temp = expressions.top();
		//Output everything of equal or higher precedence
		while(getWeight(temp) >= weight && !expressions.empty())
		{
		    cout << temp;
		    expressions.pop();
		    if(!expressions.empty())
		    {
			temp = expressions.top();
		    } 
		}
	    }
	    expressions.push(equation[i]);
	}
	else if (weight == 4)
	{
	   expressions.push(equation[i]);
	}
    }
    //Print all the remaining elements in the stack
    while(!expressions.empty())
    {
	temp = expressions.top();
	cout << temp;
	expressions.pop();
    }
    cout << endl;
}

int getWeight(char value)
{
    //Each value has it's own weights
    if(value == ')')
    {
	return 1;
    }
    else if(value == '(')
    {
	return 2;
    }
    else if(value == '+' || value == '-')
    {
	return 3;
    }
    //Operators of higher precedence have higher weights
    else if(value == '*' || value == '/')
    {
	return 4;
    }
    else 
    {
	return 0;
    }
}
