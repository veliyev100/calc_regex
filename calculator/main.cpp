#include <iostream>
#include <vector>
#include <string>
#include <cctype> // Для isspace()

// Функция для проверки, является ли символ оператором
bool isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Функция для выполнения математических операций
double applyOperation(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) throw "Ошибка: В АКАДЕМ!";
        return a / b;
    }
    return 0;
}

// Функция для проверки правильности ввода выражения
bool isValidExpression(const std::string& expr) {
    for (char c : expr) {
        if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '.' || c == ' '))
            return false;
    }
    return true;
}

int main() {
    while (true) {
        try {
            std::string expression;
            std::cout << "Введите выражение: ";
            std::getline(std::cin, expression);

            if (!isValidExpression(expression)) throw "Ошибка: Неверный ввод!";

            std::vector<double> numbers;
            std::vector<char> operators;

            if (expression[0] == '-') {
                expression = "0" + expression;
            }

            std::string currNum;

            for (size_t i = 0; i < expression.size(); ++i) {
                char c = expression[i];

                if ((c >= '0' && c <= '9') || c == '.') {
                    // Обработка чисел
                    currNum += c;
                } else if (c == '-' && (i == 0 || isOp(expression[i - 1]) || std::isspace(expression[i - 1]))) {
                    // Обработка отрицательных чисел
                    currNum += c;
                } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                    // Если в currNum что-то есть, добавляем его как число
                    if (!currNum.empty()) {
                        numbers.push_back(std::stod(currNum));
                        currNum.clear();
                    }
                    operators.push_back(c);
                }
            }

            // Если в конце остался номер
            if (!currNum.empty()) {
                numbers.push_back(std::stod(currNum));
            }

            // Обрабатываем операции умножения и деления
            for (size_t i = 0; i < operators.size(); ++i) {
                if (operators[i] == '*' || operators[i] == '/') {
                    numbers[i + 1] = applyOperation(numbers[i], numbers[i + 1], operators[i]);
                    numbers[i] = 0; // Не используемое значение
                    operators[i] = '+';  // Убираем оператор умножения или деления
                }
            }

            // Вычисление результата с учётом сложения и вычитания
            double result = numbers[0];
            for (size_t i = 0; i < operators.size(); ++i) {
                result = applyOperation(result, numbers[i + 1], operators[i]);
            }

            std::cout << "Результат: " << result << std::endl;
        } catch (const char* err) {
            std::cout << err << "\nМатематик.\n";
        }
    }
    return 0;
}
