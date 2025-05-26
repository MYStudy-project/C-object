/*n개의 좌표축에 평행한 직사각형이 입력으로 주어진다. 이 사각형들에 포함되는 영역의 면적을 구하라. 즉, 사
각형들의 합집합의 면적을 구하는 것이다. 이 문제는 “sweep line 알고리즘”이라고 불리는 우아하고 효율적인
알고리즘이 존재하지만 여기에서는 단순무식한 방법으로 풀어야 한다. 먼저 사각형의 모든 변들을 연장한 최
대 개의 수직선과 최대 2N개의 수평선들에 의해서 평면을 사각형 셀(cell)들로 분할한다. 그런 다음 각각의
셀들이 입력으로 주어진 사각형들 중의 하나에 포함되면 그 면적을 더하는 방식으로 합집합의 면적을 구한다.
입력은 input3.txt 파일로부터 받는다. 파일의 첫 줄에는 사각형의 개수 N<=100이 주어지고, 이어진 줄
에는 각 줄마다 하나의 사각형이 주어진다. 각 사각형은 2번 문제처럼 4꼭지점의 좌표와 좌표의 최소값과 최
대값을 나타내는 4개의 정수 xmin, xmax, ymin, ymax로 표현된다. 모든 좌표값은 -100,000에서 100,000사이
의 정수이다. 합집합의 면적이 정수(int) 타입의 표현 범위를 벗어나는 경우에 대해서는 고려하지 않아도 된
다. 사각형을 표현하는 클래스 Rect를 정의하여 사용하라. 이 클래스의 모든 데이터 멤버는 private으로 하
고, 사각형을 표현하는 객체들은 오로지 동적 생성된 객체만을 사용하라. 즉, Rect 타입의 이름을 가진 객체 혹
은 Rect * 타입이 아닌 Rect 타입의 벡터나 배열을 사용해서는 안된다.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class Rect {
private:
	int xmin, xmax, ymin, ymax;
public:
	Rect(int x1, int y1, int x2, int y2) {
		xmin = std::min(x1, x2);
		xmax = std::max(x1, x2);
		ymin = std::min(y1, y2);
		ymax = std::max(y1, y2);
	}
    int getXmin() { return xmin; }
	int getXmax() { return xmax; }
	int getYmin() { return ymin; }
	int getYmax() { return ymax; }
};
bool isInside(Rect* rect, int x, int y) {
	return (x >= rect->getXmin() && x <= rect->getXmax() && y >= rect->getYmin() && y <= rect->getYmax());
}

int main() {
	ifstream input("input3.txt");
	if (!input) {
		cerr << "Error opening file." << std::endl;
		return 1;
	}
	int N;
	input >> N;
	std::vector<Rect*> rectangles;
	for (int i = 0; i < N; ++i) {
		int x1, y1, x2, y2;
		input >> x1 >> y1 >> x2 >> y2;
		rectangles.push_back(new Rect(x1, y1, x2, y2));
	}
	input.close();
	int area = 0;
	for (int i = -100000; i <= 100000; ++i) {
		for (int j = -100000; j <= 100000; ++j) {
			for (auto rect : rectangles) {
				if (isInside(rect, i, j)) {
					area++;
					break;
				}
			}
		}
	}
	cout << "Total area: " << area << std::endl;
	for (auto rect : rectangles) {
		delete rect;
	}
	return 0;
}
