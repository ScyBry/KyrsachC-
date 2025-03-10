#include "Stack.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

int playGame(Stack& stack)
{
    int totalDestroyedBalls = 0;
    bool chainFound;

    do
    {
        Stack tempStack;
        int destroyedBalls = 0;
        chainFound = false;

        while (!stack.isEmpty())
        {
            int currentBall = stack.pop();
            int count = 1;

            while (!stack.isEmpty() && stack.peek() == currentBall)
            {
                count++;
                stack.pop();
            }

            if (count >= 3)
            {
                destroyedBalls += count;
                chainFound = true;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    tempStack.push(currentBall);
                }
            }
        }

        while (!tempStack.isEmpty())
        {
            stack.push(tempStack.pop());
        }

        totalDestroyedBalls += destroyedBalls;
    }
    while (chainFound);

    return totalDestroyedBalls;
}

void demonstrateStackMethods()
{
    Stack stack;


    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Стек после добавления элементов: ";
    stack.print(); // Ожидаемый вывод: 3 2 1

    // ```cpp
    // Demonstration of pop
    int poppedValue = stack.pop();
    std::cout << "Извлеченный элемент: " << poppedValue << std::endl; // Ожидаемый вывод: 3
    std::cout << "Стек после извлечения элемента: ";
    stack.print(); // Ожидаемый вывод: 2 1

    // Demonstration of peek
    int topValue = stack.peek();
    std::cout << "Верхний элемент стека: " << topValue << std::endl; // Ожидаемый вывод: 2

    // Demonstration of size
    std::cout << "Размер стека: " << stack.size() << std::endl; // Ожидаемый вывод: 2

    // Demonstration of isEmpty
    std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << std::endl; // Ожидаемый вывод: Нет

    // Demonstration of find
    int index = stack.find(1);
    std::cout << "Индекс элемента 1: " << index << std::endl; // Ожидаемый вывод: 1

    // Demonstration of copyPart
    Stack copiedStack = stack.copyPart(0, 1);
    std::cout << "Скопированная часть стека: ";
    copiedStack.print(); // Ожидаемый вывод: 2 1

    // Demonstration of loadFromFile
    stack.loadFromFile("data.txt");
    std::cout << "Стек после загрузки из файла: ";
    stack.print(); // Ожидаемый вывод зависит от содержимого файла
}

int main()
{
    SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);

    Stack stack;

    // Загрузка данных из файла
    stack.loadFromFile("data.txt");

    std::cout << "Исходная цепочка шариков: ";
    stack.print();

    // Запускаем игру
    int destroyed = playGame(stack);

    // Выводим результаты
    std::cout << "Количество уничтоженных шариков: " << destroyed << std::endl;
    std::cout << "Оставшаяся цепочка шариков: ";
    stack.print();

    // Демонстрация работы методов стека
    demonstrateStackMethods();

    return 0;
}
