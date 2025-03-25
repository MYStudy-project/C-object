/*
2차원 평면의 1사분면에서 직선 y = 2x/3 의 아래쪽에 있고 직선 y=x/3 의 위쪽에 있으면서(두직선 사이) 원점으
로부터 거리가 100이하인 정수 좌표 점의 개수는? -좌표나 -좌표가 0이거나 직선 상에 있는 점도 포
함한다. (정답: 1362)



*/

#include <iostream>
#include <cmath>

using namespace std;;

int main() {
	int x,y,dis;
	double y1, y2;
	int count = 0;
	
	for (x = 0; x <= 100; x++) {
		for (y = 0; y <= 100; y++) {
			dis = x * x + y * y;
			y1 = 2.0 * x / 3.0;
			y2 = x / 3.0;
			if (dis <= y1 * y1 + x * x && dis >= y2 * y2 + x * x && dis <= 10000) {
				count++;
			}
		}

	}
	cout << count;

}





