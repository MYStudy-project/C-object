#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

bool isDuplicate(const vector<string>& words, const string& word) {
    for (const string& w : words) {
        if (w == word) {
            return true;  // 중복이면 true
        }
    }
    return false;  // 중복이 아니면 false
}

void toLowerCaseAndRemovePunctuation(string& word) {
    string cleanedWord = "";
    for (char ch : word) {
        if (isalnum(ch)) {  // 알파벳이나 숫자만 허용
            cleanedWord += tolower(ch);  // 소문자로 변환하여 추가
        }
    }
    word = cleanedWord;
}

int main() {
    string filename = "sample.txt";

    ifstream file(filename);
    if (!file) {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(file, line)) {  // 파일에서 한 줄씩 읽기
        string word = "";
        for (char ch : line) {
            if (isalnum(ch)) {  // 알파벳이나 숫자라면
                word += ch;
            }
            else {
                if (!word.empty()) {
                    toLowerCaseAndRemovePunctuation(word);  // 단어 처리
                    if (!isDuplicate(words, word)) {  // 중복 확인
                        words.push_back(word);  // 중복이 아니라면 단어 추가
                    }
                    word = "";  // 다음 단어를 위해 초기화
                }
            }
        }
        if (!word.empty()) {  // 줄 끝에서 마지막 단어 처리
            toLowerCaseAndRemovePunctuation(word);
            if (!isDuplicate(words, word)) {
                words.push_back(word);
            }
        }
    }

    file.close();

    // 사전식으로 정렬
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if (words[i] > words[j]) {
                swap(words[i], words[j]);  // 두 단어를 교환
            }
        }
    }

    // 결과 출력
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
