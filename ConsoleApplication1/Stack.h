#pragma once

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <iostream>
#include <fstream>

class Stack
{
private:
    Node* top;

public:
    Stack();
    Stack(int value);
    Stack(const Stack& other);
    ~Stack();

    void push(int value);
    int pop();
    int peek() const;
    int size() const;

    bool isEmpty() const;
    Stack copyPart(int startIndex, int endIndex) const;
    void print() const;
    void loadFromFile(const std::string& filename);
    int find(int value) const;
    int findMax() const;
    int findMin() const;
};

#endif
