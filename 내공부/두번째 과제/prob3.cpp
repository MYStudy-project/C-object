#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100;
string words[MAX];
int counts[MAX];
int wordCount = 0;

void addWord(string word) {
    // 모든 문자를 소문자로 변환
    for (char& ch : word) {
        ch = tolower(ch);
    }

    // 기존 단어 찾기
    for (int i = 0; i < wordCount; i++) {
        if (words[i] == word) {
            counts[i]++;
            return;
        }
    }

    // 새로운 단어 추가
    words[wordCount] = word;
    counts[wordCount] = 1;
    wordCount++;
}

void sortWords() {
    // 버블 정렬 (빈도 내림차순, 빈도 동일 시 사전순)
    for (int i = wordCount - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (counts[j] < counts[j + 1] || (counts[j] == counts[j + 1] && words[j] > words[j + 1])) {
                swap(words[j], words[j + 1]);
                swap(counts[j], counts[j + 1]);
            }
        }
    }
}

int main() {
    ifstream infile("input3.txt");
    if (!infile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    string word;
    while (infile >> word) {
        addWord(word);
    }

    infile.close();
    sortWords();

    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << " : " << counts[i] << endl;
    }

    return 0;
}
