#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> buho;
    int n;
    string b;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b;
        buho.push_back(b);
    }

    int sum = stoi(buho[0]); // 첫 숫자를 sum에 미리 저장
    for (int i = 1; i < n; i += 2) {
        string op = buho[i];       // + 또는 -
        int num = stoi(buho[i + 1]); // 다음 숫자

        if (op == "+") {
            sum += num;
        }
        else if (op == "-") {
            sum -= num;
        }
    }

    cout << sum << endl;
    return 0;
}
