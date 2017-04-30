#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
    value = 0;
    next = NULL;
}

void Node::setNext(Node *node)
{
    next = node;
}

int Node::getValue()
{
    return value;
}
