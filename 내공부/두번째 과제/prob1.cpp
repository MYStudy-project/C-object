#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            int a = numbers[j], b = numbers[j + 1];
            int powerA = 1, powerB = 1;
            while (powerA <= a) powerA *= 10;
            while (powerB <= b) powerB *= 10;
            if (a * powerB > b * powerA) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }

    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}