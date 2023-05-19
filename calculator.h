#pragma once

#include <string>
#include <sstream>
#include "LinkedList.h"

bool isOperator(const string& symbol) {
    return symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/";
}

int Operation(const string& operation, int operand1, int operand2) {
    if (operation == "+")
        return operand1 + operand2;
    else if (operation == "-")
        return operand1 - operand2;
    else if (operation == "*")
        return operand1 * operand2;
    else if (operation == "/")
        return operand1 / operand2;
    cout << "Недопустимая операция." << endl; //защита, чтобы пользователь не написал какой-либо другой знак
    return 0;
}

int evaluatePostfixExpression(const string& expression, bool& success) {
    Stack stack;

    istringstream exp(expression);
    string token;

    while (exp >> token) { 
        if (isOperator(token)) { 
            if (stack.isEmpty()) { //проверяем, пуст ли стек
                success = false; //если пустой, выводим ошибку
                cout << "Введите постфиксное выржение." << endl;
                return 0;
            }

            int operand2 = stack.remove(); //проверяем корректность выражения
            if (stack.isEmpty()) {
                success = false;
                cout << "Вы ввели некорректное выражение." << endl;
                return 0;
            }

            int operand1 = stack.remove(); //проверяем деление на ноль
            if (token == "/" && operand2 == 0) {
                success = false;
                cout << "Вы делите на ноль." << endl;
                return 0;
            }
            int result = Operation(token, operand1, operand2); //совершаем операцию
            stack.push(result); //закидываем результат проведенной операции вверх стека
        }
        else {
            int operand;
            bool validOperand = true;
            try {
                operand = stoi(token);
            }
            catch (const exception&) {
                validOperand = false;
            }
            if (!validOperand) {
                success = false;
                cout << "Вы ввели некорректное выражение." << endl;
                return 0;
            }
            stack.push(operand);
        }
    }

    if (stack.isEmpty()) { //проверяем, пуст ли стек
        success = false;
        cout << "Вы ввели некорректное выражение." << endl;
        return 0;
    }

    int finalResult = stack.remove(); //удаляем финальный результат

    if (!stack.isEmpty()) { //если стек не пустой, значит было введено неверное выражение
        success = false;
        cout << "Вы ввели некорректное выражение." << endl;
        return 0;
    }

    success = true; //говорим, что всё было введено верно
    return finalResult; //возвращаем финальный результат
}
