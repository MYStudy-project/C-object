#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 1000;
string lines[MAX];
int wordCounts[MAX];
int lineCount = 0;


int countWordsAndClean(string& line) {
    string cleaned;
    int count = 0;
    bool inWord = false;

    for (char ch : line) {
        if (isspace(ch)) {
            if (inWord) {
                cleaned += ' ';
                inWord = false;
            }
        }
        else {
            cleaned += ch;
            if (!inWord) {
                count++;
                inWord = true;
            }
        }
    }

    line = cleaned;
    return count;
}

void sortLines() {
    for (int i = lineCount - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (wordCounts[j] < wordCounts[j + 1]) {
                swap(lines[j], lines[j + 1]);
                swap(wordCounts[j], wordCounts[j + 1]);
            }
        }
    }
}

int main() {
    ifstream infile("sample_lines.txt");
    if (!infile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        int wordCount = countWordsAndClean(line);
        if (wordCount > 0) { // 공백 라인 무시
            lines[lineCount] = line;
            wordCounts[lineCount] = wordCount;
            lineCount++;
        }
    }

    infile.close();
    sortLines();

    for (int i = 0; i < lineCount; i++) {
        cout << lines[i] << " : " << wordCounts[i] << endl;
    }

    return 0;
}
