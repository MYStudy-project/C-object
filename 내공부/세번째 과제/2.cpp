#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int Vector2D(const vector<vector<int>>& matrix) {
    int result = 0;
    for (int i = 0; i < matrix.size(); i++) {             // 행 반복
        for (int j = 0; j < matrix[i].size(); j++) {      // 열 반복
            if (j + 1 < matrix.size() && j + 2 < matrix.size() && j + 3 < matrix.size() < j + 4 < matrix.size()) {
                if (matrix[i][j] == 1 && matrix[i][j + 1] == 1 && matrix[i][j + 2] == 1 && matrix[i][j + 3] == 1 && matrix[i][j+4] == 1) {
                    result = 1;
                    break;
                }
            }
            if (i + 1 < matrix.size() && i + 2 < matrix.size() && i + 3 < matrix.size() && i + 4 < matrix.size()) {
                if (matrix[i][j] == 1 && matrix[i+1][j] == 1 && matrix[i+2][j] == 1 && matrix[i+3][j] == 1 && matrix[i+4][j] == 1) {
                    result = 1;
                    break;
                }
            }
            if (i + 1 < matrix.size() && i + 2 < matrix.size() && i + 3 < matrix.size() && i + 4 < matrix.size() && j + 1 < matrix.size() && j + 2 < matrix.size() && j + 3 < matrix.size() < j + 4 < matrix.size()) {
                if (matrix[i][j] == 1 && matrix[i + 1][j+1] == 1 && matrix[i + 2][j+2] == 1 && matrix[i + 3][j+3] == 1 && matrix[i + 4][j+4] == 1) {
                    result = 1;
                    break;
                }
            }
            if (i - 1 < matrix.size() && i - 2 < matrix.size() && i - 3 < matrix.size() && i - 4 < matrix.size() && j + 1 < matrix.size() && j + 2 < matrix.size() && j + 3 < matrix.size() < j + 4 < matrix.size()) {
                if (matrix[i][j] == 1 && matrix[i - 1][j + 1] == 1 && matrix[i - 2][j + 2] == 1 && matrix[i - 3][j + 3] == 1 && matrix[i - 4][j + 4] == 1) {
                    result = 1;
                    break;
                }
            }
            //2일떄
            if (j + 1 < matrix.size() && j + 2 < matrix.size() && j + 3 < matrix.size() < j + 4 < matrix.size()) {
                if (matrix[i][j] == 2 && matrix[i][j + 1] == 2 && matrix[i][j + 2] == 2 && matrix[i][j + 3] == 2 && matrix[i][j + 4] == 2) {
                    result = 2;
                    break;
                }
            }
            if (i + 1 < matrix.size() && i + 2 < matrix.size() && i + 3 < matrix.size() && i + 4 < matrix.size()) {
                if (matrix[i][j] == 2 && matrix[i + 1][j] == 2 && matrix[i + 2][j] == 2 && matrix[i + 3][j] == 2 && matrix[i + 4][j] == 2) {
                    result = 2;
                    break;
                }
            }
            if (i + 1 < matrix.size() && i + 2 < matrix.size() && i + 3 < matrix.size() && i + 4 < matrix.size() && j + 1 < matrix.size() && j + 2 < matrix.size() && j + 3 < matrix.size() < j + 4 < matrix.size()) {
                if (matrix[i][j] == 2 && matrix[i + 1][j + 1] == 2 && matrix[i + 2][j + 2] == 2 && matrix[i + 3][j + 3] == 2 && matrix[i + 4][j + 4] == 2) {
                    result = 2;
                    break;
                }
            }
            if (i - 1 < matrix.size() && i - 2 < matrix.size() && i - 3 < matrix.size() && i - 4 < matrix.size() && j + 1 < matrix.size() && j + 2 < matrix.size() && j + 3 < matrix.size() < j + 4 < matrix.size()) {
                if (matrix[i][j] == 2 && matrix[i - 1][j + 1] == 2 && matrix[i - 2][j + 2] == 2 && matrix[i - 3][j + 3] == 2 && matrix[i - 4][j + 4] == 2) {
                    result = 2;
                    break;
                }
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int row = n, col = n;
    vector<vector<int>> matrix(row, vector<int>(col, 0));

    // 값 입력 받기
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
    int total = Vector2D(matrix);
    if (total == 1) {
        cout << "black";
    }
    else if(total == 2) {
        cout << "white";
    }
    else {
        cout << "no finshed";
    }

    /*/ 출력하기
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}