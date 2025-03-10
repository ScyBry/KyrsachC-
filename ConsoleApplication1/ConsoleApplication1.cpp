// #include <iostream>
//
//using namespace std;
//
//// Класс для реализации стека
//class Stack {
//private:
//    struct Node {
//        int value;
//        Node* next;
//    };
//    Node* top;
//
//public:
//    Stack() : top(nullptr) {}
//
//    ~Stack() {
//        while (top) {
//            Node* temp = top;
//            top = top->next;
//            delete temp;
//        }
//    }
//
//    void push(int value) {
//        Node* newNode = new Node{ value, top };
//        top = newNode;
//    }
//
//    int pop() {
//        if (top) {
//            Node* temp = top;
//            int value = top->value;
//            top = top->next;
//            delete temp;
//            return value;
//        }
//        return -1;  // Если стек пуст
//    }
//
//    bool isEmpty() const {
//        return top == nullptr;
//    }
//
//    int peek() const {
//        if (top) {
//            return top->value;
//        }
//        return -1;  // Если стек пуст
//    }
//};
//
//// Функция для удаления шариков
//int removeBalls(Stack& ballsStack) {
//    int destroyed = 0;
//    bool found = true;
//
//    while (found) {
//        found = false;
//        Stack tempStack;  // Вспомогательный стек для хранения оставшихся шариков
//        Stack removalStack;  // Вспомогательный стек для удаления цепочек
//
//        int count = 1;
//        int prevBall = ballsStack.pop();
//        removalStack.push(prevBall);
//
//        // Проходим по всем элементам стека
//        while (!ballsStack.isEmpty()) {
//            int currentBall = ballsStack.pop();
//            if (currentBall == prevBall) {
//                count++;
//                removalStack.push(currentBall);
//            }
//            else {
//                if (count >= 3) {
//                    destroyed += count;  // Уничтожаем цепочку
//                    found = true;
//                }
//                else {
//                    // Переносим элементы в новый стек, если они не были уничтожены
//                    while (!removalStack.isEmpty()) {
//                        tempStack.push(removalStack.pop());
//                    }
//                }
//                count = 1;
//                prevBall = currentBall;
//                removalStack.push(currentBall);
//            }
//        }
//
//        if (count >= 3) {
//            destroyed += count;  // Уничтожаем цепочку
//            found = true;
//        }
//        else {
//            while (!removalStack.isEmpty()) {
//                tempStack.push(removalStack.pop());
//            }
//        }
//
//        // Переносим оставшиеся шарики обратно в исходный стек
//        while (!tempStack.isEmpty()) {
//            ballsStack.push(tempStack.pop());
//        }
//    }
//
//    return destroyed;
//}
//
//int main() {
//    int N;
//    cin >> N;
//    Stack ballsStack;
//
//    for (int i = 0; i < N; ++i) {
//        int ball;
//        cin >> ball;
//        ballsStack.push(ball);
//    }
//
//    int destroyed = removeBalls(ballsStack);
//
//    cout << destroyed << endl;
//
//    // Вывод оставшейся цепочки
//    Stack remainingStack;
//    while (!ballsStack.isEmpty()) {
//        remainingStack.push(ballsStack.pop());
//    }
//
//    while (!remainingStack.isEmpty()) {
//        cout << remainingStack.pop() << " ";
//    }
//
//    return 0;
//}
