#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0, 1, 0, -1 }; // 위, 오른쪽, 아래, 왼쪽
int dy[4] = { 1, 0, -1, 0 };

bool visited(int x, int y, const vector<pair<int, int>>& path) {
    for (auto p : path)
        if (p.first == x && p.second == y)
            return true;
    return false;
}

int main() {
    int x = 0, y = 0;
    vector<pair<int, int>> path;
    path.push_back({ x, y });

    while (true) {
        int dir, dist;
        cin >> dir >> dist;

        if (dir == -1 && dist == -1)
            break;

        bool valid = true;
        for (int i = 1; i <= dist; i++) {
            int nx = x + dx[dir] * i;
            int ny = y + dy[dir] * i;
            if (visited(nx, ny, path)) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "invalid move" << endl;
            continue;
        }

        // 유효하면 이동
        for (int i = 1; i <= dist; i++) {
            x += dx[dir];
            y += dy[dir];
            path.push_back({ x, y });
        }

        cout << x << " " << y << endl;
    }

    return 0;
}
