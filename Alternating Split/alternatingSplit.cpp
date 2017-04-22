#include <iostream>
#include "Node.h"

using namespace std;

void menu(); 
void addNode(Node *list);
void printList(Node *list);


int main()
{
    int input = 0;

    Node **list = NULL;

    menu();

    do
    {

	cin >> input;

	switch(input)
	{
	    case 1: addNode(*list);
		    break;
	    case 2: printList(*list);
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
    Node *temp = NULL;
    list = new Node;
    while(temp != NULL)
    {
	temp = temp->next;
    }
    Node* node = new Node;
    temp = node;
    node->setNext(NULL);
}
void splitList(Node *list)
{
    int i = 1;
    Node *odd, *even, *temp;
    *temp = *list;
    while(temp != NULL)
    {
	if(i == 1)
	{
	    *odd = *temp;
	    odd->next = NULL;
	    odd = odd->next;
	}
	else if(i == 2)
	{
	    *even = *temp;
	    even->next = NULL;
	    even = even->next;
	}
	else if(i % 2 == 0)
	{
	    *even->next = *temp;
	    even->next->next = NULL;
	    even = even->next;
	}
	else if(i % 2 == 1)
	{
	    *odd->next = *temp;
	    odd->next->next = NULL;
	    odd = odd->next;
	}
	temp = temp->next;
    }

    while(odd->next != NULL)
    {
	cout << odd->value;
	odd = odd->next;
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

