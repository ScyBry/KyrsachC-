#pragma once
#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int data;
    Node* next;

    friend class Stack;

public:
    Node();
    Node(int value);
    Node(const Node& other);
};

#endif
