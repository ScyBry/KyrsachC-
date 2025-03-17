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

                std::cout << "Уничтожено " << count << " шариков со значением " << currentBall << std::endl;
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

void showMethods()
{
    Stack stack;

    std::cout << "Демонстрация работы стека:\n";


    std::cout << "\nЛистинг 4.2 – Добавляем элементы в стек (push)\n";
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Стек после добавления элементов: ";
    stack.print();

 
    std::cout << "\nЛистинг 4.3 – Извлекаем элемент из стека (pop)\n";
    int poppedValue = stack.pop();
    std::cout << "Извлеченный элемент: " << poppedValue << std::endl;
    std::cout << "Стек после извлечения элемента: ";
    stack.print();

  
    std::cout << "\nЛистинг 4.4 – Получаем верхний элемент стека (peek)\n";
    int topValue = stack.peek();
    std::cout << "Верхний элемент стека: " << topValue << std::endl;

    
    std::cout << "\nЛистинг 4.5 – Определяем размер стека (size)\n";
    std::cout << "Размер стека: " << stack.size() << std::endl;

 
    std::cout << "\nЛистинг 4.6 – Проверяем, пуст ли стек (isEmpty)\n";
    std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << std::endl;

    
    std::cout << "\nЛистинг 4.7 – Ищем элемент 1 в стеке (find)\n";
    int index = stack.find(1);
    std::cout << "Индекс элемента 1: " << index << std::endl;


    std::cout << "\nЛистинг 4.8 – Ищем максимальный элемент в стеке (findMax)\n";
    int maxValue = stack.findMax();
    std::cout << "Максимальный элемент стека: " << maxValue << std::endl;


    std::cout << "\nЛистинг 4.9 – Ищем минимальный элемент в стеке (findMin)\n";
    int minValue = stack.findMin();
    std::cout << "Минимальный элемент стека: " << minValue << std::endl;

  
    std::cout << "\nЛистинг 4.10 – Копируем часть стека (copyPart)\n";
    Stack copiedStack = stack.copyPart(0, 1);
    std::cout << "Скопированная часть стека: ";
    copiedStack.print();

  
    std::cout << "\nЛистинг 4.11 – Загружаем элементы из файла в стек (loadFromFile)\n";
    stack.loadFromFile("data.txt");
    std::cout << "Стек после загрузки из файла: ";
    stack.print();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Stack stack;

    stack.loadFromFile("data.txt");

    std::cout << "Исходная цепочка шариков: ";
    stack.print();

    int destroyed = playGame(stack);

    std::cout << "Количество уничтоженных шариков: " << destroyed << std::endl;
    std::cout << "Оставшаяся цепочка шариков: ";
    stack.print();

    showMethods();

    return 0;
}
