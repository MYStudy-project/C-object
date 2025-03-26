#include <iostream>
#include <vector>

using namespace std;

void compute_set(vector<int>& A, vector<int>& B) {
    int i = 0, j = 0;
    vector<int> result;

    // A와 B를 순회하면서 합집합에서 교집합을 제거
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        }
        else if (A[i] > B[j]) {
            result.push_back(B[j]);
            j++;
        }
        else {
            // 교집합 요소는 추가하지 않고 넘어감
            i++;
            j++;
        }
    }

    // A에 남은 원소 추가
    while (i < A.size()) {
        result.push_back(A[i]);
        i++;
    }

    // B에 남은 원소 추가
    while (j < B.size()) {
        result.push_back(B[j]);
        j++;
    }

    // A를 결과 벡터로 교체
    A = result;
}

int main() {
    int m, n, x;
    vector<int> A, B;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        A.push_back(x);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        B.push_back(x);
    }

    compute_set(A, B);

    for (auto item : A)
        cout << item << " ";
    cout << endl;

    return 0;
}
