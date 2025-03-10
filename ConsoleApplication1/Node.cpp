#include "Node.h"


Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::Node(int value)
{
    data = value;
    next = nullptr;
}

Node::Node(const Node& other)
{
    data = other.data;
    next = other.next;
}
