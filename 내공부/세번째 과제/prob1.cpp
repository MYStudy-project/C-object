#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

vector<string> words;
vector<vector<int>> lineNums;
vector<string> lines;

void makeIndex(string fileName);
void handle_find(string keyword);
void addWord(string word, int lineNum);
int findWord(string keyword);
vector<string> split_line(string line, char delimiter);
string cleanWord(string word);
string toLower(string word);
void sortIndex();

int main() {
    string command;
    while (true) {
        cout << "$ ";
        cin >> command;
        if (command == "read") {
            string fileName;
            cin >> fileName;
            makeIndex(fileName);
        }
        else if (command == "find") {
            string keyword;
            cin >> keyword;
            handle_find(toLower(keyword));
        }
        else if (command == "exit")
            break;
    }
    return 0;
}

void makeIndex(string fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    lines.clear();
    words.clear();
    lineNums.clear();

    while (getline(theFile, line)) {
        lines.push_back(line);
        vector<string> tokens = split_line(line, ' ');
        vector<string> uniqueWordsInLine;
        for (auto raw : tokens) {
            string cleaned = cleanWord(raw);
            if (cleaned.length() >= 3) {
                cleaned = toLower(cleaned);
                if (find(uniqueWordsInLine.begin(), uniqueWordsInLine.end(), cleaned) == uniqueWordsInLine.end()) {
                    addWord(cleaned, lineNum);
                    uniqueWordsInLine.push_back(cleaned);
                }
            }
        }
        lineNum++;
    }
    theFile.close();
    sortIndex();
}

vector<string> split_line(string line, char delimiter) {
    vector<string> tokens;
    stringstream sstream(line);
    string str;
    while (getline(sstream, str, delimiter))
        tokens.push_back(str);
    return tokens;
}

string cleanWord(string word) {
    string cleaned;
    for (char c : word)
        if (isalpha(c))
            cleaned += c;
    return cleaned;
}

string toLower(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

void addWord(string word, int lineNum) {
    int index = findWord(word);
    if (index > -1) {
        // 중복된 lineNum은 추가하지 않음
        if (find(lineNums[index].begin(), lineNums[index].end(), lineNum) == lineNums[index].end()) {
            lineNums[index].push_back(lineNum);
        }
    }
    else {
        words.push_back(word);
        lineNums.push_back({ lineNum });
    }
}

int findWord(string word) {
    for (int i = 0; i < words.size(); i++)
        if (words[i] == word)
            return i;
    return -1;
}

void handle_find(string keyword) {
    int index = findWord(keyword);
    if (index != -1) {
        int count = lineNums[index].size();
        cout << "The word \"" << keyword << "\" appears " << count << " time" << (count > 1 ? "s" : "") << " in the following lines:\n";
        
        vector<bool> printed(lines.size(), false);
        for (int lineNum : lineNums[index]) {
            if (!printed[lineNum]) {
                cout << lineNum << ": " << lines[lineNum] << endl;
                printed[lineNum] = true;
            }
        }
    }
    else {
        cout << "The word \"" << keyword << "\" doesn’t appear." << endl;
    }
}

void sortIndex() {
    vector<pair<string, vector<int>>> temp;
    for (int i = 0; i < words.size(); i++) {
        temp.push_back({ words[i], lineNums[i] });
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++) {
        words[i] = temp[i].first;
        lineNums[i] = temp[i].second;
    }
}
