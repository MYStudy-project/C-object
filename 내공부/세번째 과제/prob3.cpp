#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class Segment {
public:
    Point p1, p2;
    bool isVertical() const {
        return p1.x == p2.x;
    }
    bool isHorizontal() const {
        return p1.y == p2.y;
    }
};

// 교차점 계산 함수
bool intersect(const Segment& s1, const Segment& s2, Point& out) {
    if (s1.isHorizontal() && s2.isVertical()) {
        // s1: 수평, s2: 수직
        if (min(s1.p1.x, s1.p2.x) <= s2.p1.x && s2.p1.x <= max(s1.p1.x, s1.p2.x) &&
            min(s2.p1.y, s2.p2.y) <= s1.p1.y && s1.p1.y <= max(s2.p1.y, s2.p2.y)) {
            out = Point(s2.p1.x, s1.p1.y);
            return true;
        }
    }
    else if (s1.isVertical() && s2.isHorizontal()) {
        // s1: 수직, s2: 수평 → 순서 바꿔서 호출된 경우
        return intersect(s2, s1, out);
    }
    return false;
}

bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int N;
    cin >> N;
    vector<Segment> segments(N);
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments[i].p1 = Point(x1, y1);
        segments[i].p2 = Point(x2, y2);
    }

    vector<Point> intersections;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            Point inter;
            if (intersect(segments[i], segments[j], inter)) {
                // 중복 교차점 방지
                if (find(intersections.begin(), intersections.end(), inter) == intersections.end())
                    intersections.push_back(inter);
            }
        }
    }

    sort(intersections.begin(), intersections.end(), comparePoints);

    for (const auto& p : intersections) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}
