#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };

vector<string> dictionary;
vector<string> foundWords;
vector<vector<char>> grid;
int N;

bool inDictionary(const string& word) {
    for (const string& w : dictionary)
        if (w == word)
            return true;
    return false;
}

bool alreadyFound(const string& word) {
    for (const string& w : foundWords)
        if (w == word)
            return true;
    return false;
}

void loadDictionary(const string& filename) {
    ifstream file(filename);
    string word;
    while (file >> word)
        dictionary.push_back(word);
    file.close();
}

void loadPuzzle(const string& filename) {
    ifstream file(filename);
    file >> N;
    grid.resize(N, vector<char>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> grid[i][j];
    file.close();
}

void searchFrom(int x, int y) {
    for (int dir = 0; dir < 8; ++dir) {
        string word = "";
        int nx = x, ny = y;
        for (int len = 1; len <= N; ++len) {
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                break;
            word += grid[nx][ny];
            if (word.length() >= 2 && inDictionary(word) && !alreadyFound(word))
                foundWords.push_back(word);
            nx += dx[dir];
            ny += dy[dir];
        }
    }
}

int main() {
    loadDictionary("dictionary.txt");
    loadPuzzle("puzzle.txt");

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            searchFrom(i, j);

    for (const string& word : foundWords)
        cout << word << endl;

    return 0;
}
