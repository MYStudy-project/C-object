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
        if (isalnum(ch)) {
            cleanedWord += tolower(ch);  
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

    while (getline(file, line)) {
        string word = "";
        for (char ch : line) {
            if (isalnum(ch)) { 
                word += ch;
            }
            else {
                if (!word.empty()) {
                    toLowerCaseAndRemovePunctuation(word); 
                    if (!isDuplicate(words, word)) {
                        words.push_back(word); 
                    }
                    word = ""; 
                }
            }
        }
        if (!word.empty()) { 
            toLowerCaseAndRemovePunctuation(word);
            if (!isDuplicate(words, word)) {
                words.push_back(word);
            }
        }
    }

    file.close();

    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if (words[i] > words[j]) {
                swap(words[i], words[j]);  
            }
        }
    }

    // 결과 출력
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
