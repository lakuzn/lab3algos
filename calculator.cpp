#include <string>
#include "LinkedList.h"
#include "calculator.h"


int main() {
    setlocale(LC_ALL, "RU");
    while (true) {
        string expression;
        cout << "Введите постфиксное выражение. Для выхода из программы введите 0: ";
        getline(cin, expression);

        if (expression == "0") {
            break;
        }

        bool success;
        int result = evaluatePostfixExpression(expression, success);

        if (success) {
            cout << "Результат: " << result << endl;
        }
    }

    return 0;
}