/*
2���� ����� 1��и鿡�� ���� y = 2x/3 �� �Ʒ��ʿ� �ְ� ���� y=x/3 �� ���ʿ� �����鼭(������ ����) ������
�κ��� �Ÿ��� 100������ ���� ��ǥ ���� ������? -��ǥ�� -��ǥ�� 0�̰ų� ���� �� �ִ� ���� ��
���Ѵ�. (����: 1362)



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





