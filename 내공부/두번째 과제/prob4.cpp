#include <iostream>
#include <string>
using namespace std;

int calculateExpression(const string& expr) {
    int result = 0, num = 0;
    char op = '+';

    for (char ch : expr) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0'); //문자열을 숫자로 바꾸는 코드
        }
        else {
            if (op == '+') result += num;
            else if (op == '-') result -= num;
            op = ch;
            num = 0;
        }
    }

    if (op == '+') result += num;
    else if (op == '-') result -= num;

    return result;
}

int main() {
    string expression;
    cin >> expression;
    cout << calculateExpression(expression) << endl;
    return 0;
}
