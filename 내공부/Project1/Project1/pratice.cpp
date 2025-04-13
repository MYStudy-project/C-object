#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string commonPrefix;
    cin >> commonPrefix;

    for (int i = 1; i < n; ++i) {
        string word;
        cin >> word;

        int minLength = min(commonPrefix.length(), word.length());
        int j = 0;

        while (j < minLength && commonPrefix[j] == word[j]) {
            ++j;
        }

        commonPrefix = commonPrefix.substr(0, j);

        if (commonPrefix.empty()) {
            break;
        }
    }

    cout << commonPrefix << endl;

    return 0;
}
