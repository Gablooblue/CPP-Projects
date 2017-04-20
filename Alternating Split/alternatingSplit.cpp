#include <iostream>
#include "Node.h"

using namespace std;

void menu(); 
void addNode(Node *list);
void printList(Node *list);


int main()
{
    int input = 0;

    Node *list = NULL;

    menu();

    do
    {

	cin >> input;

	switch(input)
	{
	    case 1: addNode(list);
		    break;
	    case 2: printList(list);
		    break;
	    case 3: break;
	    default: cout << "Input a valid number" << endl;
		    break;
	}
    }while(input > 3 || input < 1);
}

void menu()
{
    cout << "Alternating split menu" << endl;
    cout << '\t' << "[1] Add node" << endl;
    cout << '\t' << "[2] Print splitted list" << endl;
    cout << '\t' << "[3] exit" << endl;

}

void addNode(Node *list)
{
    Node *temp;
    Node *prev;
    *temp = *list;
    *prev = *list;
    while(temp != NULL)
    {
	temp = temp->next;
    }
    while(prev->next != temp && prev != temp)
    {
	prev = prev->next;
    }
    Node* node = new Node;
    temp = node;
    prev->setNext(temp);
    node->setNext(NULL);
}
void splitList(Node *list)
{
    int i = 1;
    Node *odd, *even, *temp;
    *temp = *list;
    while(temp != NULL)
    {
	if(i % 2 == 0)
	{

	}
    }
}
void printList(Node *list)
{
    Node *temp;
    *temp = *list;
    int i;
    while(temp != NULL)
    {
	cout << temp->getValue();
	i++;
    }
}

