#include "Stack.h"

Stack::Stack()
{
    top = nullptr;
}

Stack::Stack(int value)
{
    top = new Node(value);
}


Stack::Stack(const Stack& other) : top(nullptr)
{
    if (other.top == nullptr)
    {
        return;
    }

    Stack temp;
    Node* current = other.top;

    while (current != nullptr)
    {
        temp.push(current->data);
        current = current->next;
    }

    while (!temp.isEmpty())
    {
        push(temp.pop());
    }
}


Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}


void Stack::push(int value)
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}


int Stack::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Стек пуст!");
    }
    int value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}


int Stack::peek() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Стек пуст!");
    }
    return top->data;
}

int Stack::size() const
{
    int count = 0;
    Node* current = top;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

//

bool Stack::isEmpty() const
{
    return top == nullptr;
}


void Stack::print() const
{
    Node* current = top;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n";
}

Stack Stack::copyPart(int startIndex, int endIndex) const
{
    Stack newStack;
    Stack reversedStack;
    Node* current = top;
    int index = 0;

    while (current != nullptr)
    {
        if (index >= startIndex && index <= endIndex)
        {
            newStack.push(current->data);
        }
        current = current->next;
        index++;
    }

    while (!newStack.isEmpty())
    {
        reversedStack.push(newStack.pop());
    }

    return reversedStack;
}

void Stack::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось открыть файл!");
    }

    int N, value;
    file >> N;
    for (int i = 0; i < N; ++i)
    {
        file >> value;
        push(value);
    }

    file.close();
}

int Stack::find(int value) const
{
    Node* current = top;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return current->data;
        }

        current = current->next;
    }

    throw std::out_of_range("Элемент не найден в стеке!");
}

int Stack::findMax() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Стек пуст, поиск максимального элемента невозможен.");
    }

    Node* current = top;
    int maxValue = current->data;

    while (current != nullptr)
    {
        if (current->data > maxValue)
        {
            maxValue = current->data;
        }
        current = current->next;
    }

    return maxValue;
}

int Stack::findMin() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Стек пуст, поиск минимального элемента невозможен.");
    }

    Node* current = top;
    int minValue = current->data;

    while (current != nullptr)
    {
        if (current->data < minValue)
        {
            minValue = current->data;
        }
        current = current->next;
    }

    return minValue;
}
