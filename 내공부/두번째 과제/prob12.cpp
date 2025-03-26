#include <iostream>
#include <vector>

using namespace std;

void sort_vector(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                // 값 교환
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

void remove_duplicates(vector<int>& vec) {
    vector<int> unique_vec;
    if (vec.empty()) return;

    unique_vec.push_back(vec[0]); // 첫 번째 요소는 무조건 추가
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] != vec[i - 1]) {
            unique_vec.push_back(vec[i]);
        }
    }

    vec = unique_vec; // 중복 제거된 벡터로 교체
}

int main() {
    int n, x;
    vector<int> numbers;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        numbers.push_back(x);
    }

    sort_vector(numbers);  // 정렬 수행
    remove_duplicates(numbers);  // 중복 제거 수행

    // 결과 출력
    cout << numbers.size() << " :";
    for (int num : numbers) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
