#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 중복을 체크하는 함수
bool isDuplicate(const vector<string>& words, const string& word) {
    for (const string& w : words) {
        if (w == word) {
            return true;  // 중복이면 true
        }
    }
    return false;  // 중복이 아니면 false
}

// 사전식으로 정렬하는 함수 (버블 정렬을 사용)
void sortWords(vector<string>& words) {
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if (words[i] > words[j]) {
                // 두 단어를 교환
                string temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main() {
    vector<string> words;  // 단어 목록
    string input;

    while (true) {
        cin >> input;

        if (input == "exit") {
            break;  // "exit" 입력 시 종료
        }

        if (isDuplicate(words, input)) {
            cout << "duplicate" << endl;  // 중복된 단어는 "duplicate" 출력
        }
        else {
            words.push_back(input);  // 새로운 단어는 목록에 추가
            sortWords(words);  // 목록을 사전식으로 정렬
            for (const string& word : words) {
                cout << word << " ";  // 사전식으로 정렬된 목록 출력
            }
            cout << endl;
        }
    }

    return 0;
}
