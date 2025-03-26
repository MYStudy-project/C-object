#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sort_strings(vector<string>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j].length() > vec[j + 1].length() ||
                (vec[j].length() == vec[j + 1].length() && vec[j] > vec[j + 1])) {
                // 문자열 교환
                string temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    sort_strings(words);  // 정렬 수행

    // 결과 출력
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
