#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;  // 양의 정수 n 입력 받기

    string commonPrefix;
    cin >> commonPrefix;  // 첫 번째 단어 입력 받기

    // n개의 단어를 입력 받으면서 공통 접두사 찾기
    for (int i = 1; i < n; ++i) {
        string word;
        cin >> word;

        // 공통 접두사를 찾기 위해 두 단어를 비교
        int minLength = min(commonPrefix.length(), word.length());
        int j = 0;

        while (j < minLength && commonPrefix[j] == word[j]) {
            ++j;  // 공통 접두사 길이 늘리기
        }

        commonPrefix = commonPrefix.substr(0, j);  // 가장 긴 공통 접두사로 갱신

        // 만약 공통 접두사가 비어 있으면 더 이상 비교할 필요 없음
        if (commonPrefix.empty()) {
            break;
        }
    }

    cout << commonPrefix << endl;  // 가장 긴 공통 접두사 출력

    return 0;
}
