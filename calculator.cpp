#include "calculator.h"
#include <stdexcept>
#include <regex>

double applyOperation(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) throw "Ошибка: Деление на ноль!";
        return a / b;
    }
    return 0;
}

bool MathValid(const std::string& str) {
    std::regex pattern("^\s*-?\d+(\.\d+)?\s*([\+\-\*/]\s*-?\d+(\.\d+)?\s*)*$");
    return std::regex_match(str, pattern);
}
