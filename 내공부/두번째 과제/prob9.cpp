#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Entry {
    string word;
    string definition;
};

vector<Entry> dictionary; // 동적 크기의 단어 목록

// 파일을 읽어 벡터에 저장
void loadDictionary(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "파일을 열 수 없습니다: " << filename << endl;
        exit(1);
    }

    Entry entry;
    while (file >> entry.word) {
        file.ignore(); // 탭 문자 제거
        getline(file, entry.definition);
        dictionary.push_back(entry);
    }
    file.close();
}

void sortDictionary() {
    int n = dictionary.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dictionary[j].word > dictionary[j + 1].word) {
                swap(dictionary[j], dictionary[j + 1]);
            }
        }
    }
}

// 이진 탐색 (Binary Search) - 단어 찾기
int binarySearch(const string& query) {
    int left = 0, right = dictionary.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dictionary[mid].word == query)
            return mid;
        else if (dictionary[mid].word < query)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // 단어를 찾지 못한 경우
}

// 접두어 검색
void prefixSearch(const string& query) {
    cout << "Results of prefix search:" << endl;
    for (const auto& entry : dictionary) {
        if (entry.word.find(query) == 0) { // 접두어가 포함된 단어 출력
            cout << entry.word << ": " << entry.definition << endl;
        }
    }
}

// 단어 검색 기능
void searchWord(const string& query) {
    int index = binarySearch(query);

    if (index != -1) {
        // 단어가 존재하면 출력
        cout << query << endl;
        cout << dictionary[index].definition << endl;
    }
    else {
        // 단어가 없는 경우
        cout << query << "\nNot found" << endl;

        // 사전에서 바로 앞 단어 찾기
        int lowerIdx = -1, upperIdx = -1;
        for (int i = 0; i < dictionary.size(); i++) {
            if (dictionary[i].word < query)
                lowerIdx = i;
            else if (dictionary[i].word > query && upperIdx == -1)
                upperIdx = i;
        }

        // 앞 단어 출력
        if (lowerIdx != -1)
            cout << "- " << dictionary[lowerIdx].word << ": " << dictionary[lowerIdx].definition << endl;

        // 다음 단어 출력
        if (upperIdx != -1)
            cout << "+ " << dictionary[upperIdx].word << ": " << dictionary[upperIdx].definition << endl;
    }

    // 접두어 검색 실행
    prefixSearch(query);
}

int main() {
    string filename = "shuffled_dict.txt"; // 파일 경로
    loadDictionary(filename);
    sortDictionary(); // 파일을 정렬

    string query;
    cout << "검색할 단어를 입력하세요: ";
    cin >> query;

    searchWord(query);

    return 0;
}
