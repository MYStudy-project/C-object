#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void sort_words(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (words[j] > words[j + 1]) {
                string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main() {
    ifstream file("harry.txt");
    if (!file) {
        cout << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    vector<string> words;
    string word;

    // 파일에서 단어 읽기
    while (file >> word) {
        bool exists = false;

        // 중복 확인
        for (string w : words) {
            if (w == word) {
                exists = true;
                break;
            }
        }

        // 중복이 없으면 추가
        if (!exists) {
            words.push_back(word);
        }
    }

    file.close();

    // 단어 정렬 (사전순)
    sort_words(words);

    // 사용자 입력
    string prefix;
    cout << "검색할 단어를 입력하세요: ";
    cin >> prefix;

    // 접두어로 시작하는 단어 찾기
    int count = 0;
    for (const string& w : words) {
        if (w.find(prefix) == 0) {  // 접두어로 시작하는지 확인
            cout << w << endl;
            count++;
        }
    }

    // 결과 출력
    cout << "찾은 단어 개수: " << count << endl;

    return 0;
}
