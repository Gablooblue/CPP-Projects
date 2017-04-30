#include <iostream>
#include "Node.h"

using namespace std;

void menu(); 
void addNode(Node*& list);
void printList(Node*& list);
void splitList(Node*& list);
bool isListValid(Node*& list);


int main()
{
    int input = 0;

    Node *list = NULL;

    while(input != 4)
    {
	menu();
	do
	{
	    cout << "Choose an option: ";
	    cin >> input;

	    switch(input)
	    {
		case 1: addNode(list);
			break;
		case 2: splitList(list);
			break;
		case 3: printList(list);
			break;
		case 4: break;
		default: cout << "Input a valid number" << endl;
			break;
	    }
	}while(input > 4 || input < 1);
    }
}

void menu()
{
    //Menu
    cout << "Alternating split menu" << endl;
    cout << '\t' << "[1] Add node" << endl;
    cout << '\t' << "[2] Print splitted list" << endl;
    cout << '\t' << "[3] Print unsplitted list" << endl;
    cout << '\t' << "[4] Exit" << endl;
}

void addNode(Node*& list)
{
    int input;
    cout << "Input a value: ";
    cin >> input;
    cout << endl;
    Node* temp = list;

    //Creats a node object
    Node* newNode = new Node;
    //Assigns values to the newly created node
    newNode->next = NULL;
    newNode->value = input;

    //If the list is empty, inserts node as head
    if(temp == NULL)
    {
	list = newNode;
    }
    //else it inserts node as the next node
    else
    {
	//Loops until it hits the end of the list
	while(temp->next != NULL)
	{
	    temp = temp->next;
	}
	//Adds node to the end of the list
	temp->next = newNode;
    }
    return;
}
void splitList(Node*& list)
{
    int i = 1;
    //I couldn't think of a better name for these pointers
    Node *odd, *even, *temp, *odd_temp, *even_temp;
    temp = list;

    //Checks if there is 2 or more elements in the list
    if(isListValid(list))
    {
	//Checks if the list is not NULL
	while(temp != NULL )
	{
	    //Creates a new node and assigns the values
	    Node* newNode = new Node;
	    newNode->value = temp->value;
	    newNode->next = NULL;
	    //If it's the first element in the odd list
	    //it makes the node the head
	    if(i == 1)
	    {
		odd = newNode;
		odd_temp = odd;
	    }
	    //If it's the first element in the even list 
	    //it makes the node the head
	    else if(i == 2)
	    {
		even = newNode;
		even_temp = even;
	    }
	    //Else it adds the node to the end of the respective lists 
	    else if(i % 2 == 0)
	    {
		even_temp->next = newNode;
		even_temp = even_temp->next;
	    }
	    else if(i % 2 == 1)
	    {
		odd_temp->next = newNode;
		odd_temp = odd_temp->next;
	    }
	    temp = temp->next;
	    i++;
	}

	//Prints the lists
	cout << "Odd: ";
	printList(odd);
	cout << endl;
	cout << "Even: ";
	printList(even);
	cout << endl;
    }    
    //If there is less than 2 elements on the list
    else
    {
	cout << "There aren't enough elements in the list" << endl;
    }
}

void printList(Node*& list)
{
    Node *temp;
    temp = list;
    //Iterates over every element in the list and prints the value
    while(temp != NULL)
    {
	cout << temp->getValue() << " "; 
	temp = temp->next;
    }
    cout << endl;
}

/**
 * Checks if there is 2 or more elements in the list
 * @returns bool (declares if the list has 2 or more elements)
 */
bool isListValid(Node*& list)
{   
    Node *temp;
    int nodeNum = 0;
    temp = list;

    while(temp != NULL)
    {
	nodeNum++;
	temp = temp->next;
    }

    return(nodeNum >= 2);

}
