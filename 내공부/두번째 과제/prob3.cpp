#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

const int MAX = 1000;

int main() {
    string words[MAX];   // 고유한 단어 저장
    int count[MAX] = { 0 }; // 단어별 개수
    int wordcount = 0;   // 고유 단어 개수

    string word;
    ifstream infile("input34.txt");

    if (!infile) {
        cout << "파일을 열 수 없습니다!" << endl;
        return 1;
    }

    while (infile >> word) {
        // 단어를 소문자로 변환
        for (char& ch : word) {
            ch = tolower(ch);
        }

        // 단어가 이미 존재하는지 확인
        bool found = false;
        for (int i = 0; i < wordcount; i++) {
            if (words[i] == word) {
                count[i]++;
                found = true;
                break;
            }
        }

        // 새 단어라면 추가
        if (!found) {
            words[wordcount] = word;
            count[wordcount] = 1;
            wordcount++;
        }
    }

    infile.close();

    // 결과 출력
    for (int i = 0; i < wordcount; i++) {
        cout << words[i] << " " << count[i] << endl;
    }

    return 0;
}
