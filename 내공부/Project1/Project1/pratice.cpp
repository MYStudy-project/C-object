#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("table.txt");
    ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        cout << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    int rows, cols;
    inputFile >> rows >> cols; // 첫 줄에서 행, 열 개수 읽기
    inputFile.ignore(); // 개행 문자 제거

    string line;
    while (getline(inputFile, line)) {
        vector<string> tokens;
        stringstream ss(line);
        string token;

        // '&'을 기준으로 데이터 분리
        while (getline(ss, token, '&')) {
            // 불필요한 공백 제거
            stringstream tokenStream(token);
            string word, cleaned;
            while (tokenStream >> word) {
                if (!cleaned.empty()) cleaned += " ";
                cleaned += word;
            }
            // 빈 데이터가 아닐 경우 저장
            if (!cleaned.empty()) {
                tokens.push_back(cleaned);
            }
        }

        // 정리된 데이터를 출력 파일에 저장
        for (size_t i = 0; i < tokens.size(); i++) {
            if (i > 0) outputFile << " "; // 칸 사이 띄어쓰기
            outputFile << tokens[i];
        }
        outputFile << endl; // 한 줄 끝
    }

    inputFile.close();
    outputFile.close();

    cout << "출력이 완료되었습니다! (output.txt 확인)" << endl;
    return 0;
}
