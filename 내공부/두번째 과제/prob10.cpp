#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sorted_merge(vector<string>& first, vector<string>& second) {
    int i = 0, j = 0;
    vector<string> merged;

    // 두 벡터를 병합하면서 정렬 유지
    while (i < first.size() && j < second.size()) {
        if (first[i] <= second[j]) {
            merged.push_back(first[i]);
            i++;
        }
        else {
            merged.push_back(second[j]);
            j++;
        }
    }

    // first에 남은 요소 추가
    while (i < first.size()) {
        merged.push_back(first[i]);
        i++;
    }

    // second에 남은 요소 추가
    while (j < second.size()) {
        merged.push_back(second[j]);
        j++;
    }

    // first를 병합된 결과로 업데이트
    first = merged;
}

int main() {
    int m, n;
    string str;
    vector<string> first, second;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> str;
        first.push_back(str);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        second.push_back(str);
    }

    sorted_merge(first, second);

    for (auto item : first)
        cout << item << " ";
    cout << endl;

    return 0;
}
