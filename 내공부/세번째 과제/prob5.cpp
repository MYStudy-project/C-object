#include <iostream>
#include <vector>
using namespace std;

const int EMPTY = 0, BLACK = 1, WHITE = 2;
const int SIZE = 8;
int board[SIZE][SIZE];

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void initBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = EMPTY;

    board[3][3] = WHITE;
    board[4][4] = WHITE;
    board[3][4] = BLACK;
    board[4][3] = BLACK;
}

void printBoard() {
    cout << "  ";
    for (int i = 0; i < SIZE; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == BLACK) cout << "B ";
            else if (board[i][j] == WHITE) cout << "W ";
            else cout << ". ";
        }
        cout << endl;
    }
}

int countStoneToCapture(int x, int y, int color) {
    if (board[x][y] != EMPTY) return 0;
    int count = 0;
    int opponent = (color == BLACK) ? WHITE : BLACK;

    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        int temp = 0;

        while (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE && board[nx][ny] == opponent) {
            temp++;
            nx += dx[d];
            ny += dy[d];
        }

        if (temp > 0 && nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE && board[nx][ny] == color)
            count += temp;
    }
    return count;
}

bool isValidMove(int x, int y, int color) {
    return countStoneToCapture(x, y, color) > 0;
}

void makeMove(int x, int y, int color) {
    int opponent = (color == BLACK) ? WHITE : BLACK;
    board[x][y] = color;

    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        vector<pair<int, int>> toFlip;

        while (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE && board[nx][ny] == opponent) {
            toFlip.push_back({ nx, ny });
            nx += dx[d];
            ny += dy[d];
        }

        if (!toFlip.empty() && nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE && board[nx][ny] == color) {
            for (auto p : toFlip) {
                board[p.first][p.second] = color;
            }
        }
    }
}

bool hasValidMove(int color) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (isValidMove(i, j, color))
                return true;
    return false;
}

pair<int, int> getBestMove(int color) {
    int maxCount = -1;
    pair<int, int> bestMove = { -1, -1 };

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int count = countStoneToCapture(i, j, color);
            if (count > maxCount) {
                maxCount = count;
                bestMove = { i, j };
            }
        }
    }

    return bestMove;
}

int main() {
    initBoard();
    printBoard();

    while (true) {
        if (hasValidMove(BLACK)) {
            int x, y;
            while (true) {
                cout << "Your move (row col): ";
                cin >> x >> y;
                if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && isValidMove(x, y, BLACK)) {
                    makeMove(x, y, BLACK);
                    break;
                }
                else {
                    cout << "Invalid move. Try again." << endl;
                }
            }
            printBoard();
        }
        else {
            cout << "You have no valid moves. Turn skipped." << endl;
        }

        if (hasValidMove(WHITE)) {
            pair<int, int> move = getBestMove(WHITE);
            cout << "Computer moves at: " << move.first << " " << move.second << endl;
            makeMove(move.first, move.second, WHITE);
            printBoard();
        }
        else {
            cout << "Computer has no valid moves. Turn skipped." << endl;
        }

        if (!hasValidMove(BLACK) && !hasValidMove(WHITE)) {
            cout << "Game over!" << endl;
            break;
        }
    }

    return 0;
}
