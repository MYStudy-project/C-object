/*
 2���� ��¥�� �Է¹��� �� �� �� ù ��° ��¥�� �� �̸��� -1, �� ��° ��¥�� �� �̸��� 1, �� ��¥
�� �����ϸ� 0�� ����ϴ� ���α׷��� �ۼ��϶�. ������ ��¥�� ��, ��, ���� ��Ÿ���� 3���� ������
�־�����. ��¥�� ��ȿ���� üũ�� �ʿ�� ����.



*/

#include <iostream>

using namespace std;;

int main() {


	int a, b, c, d, e, f;

	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		if (i == 0) {
			a = n;
		}
		else if (i == 1) {
			b = n;
		}
		else if (i == 2) {
			c = n;
		}
		else if (i == 3) {
			d = n;
		}
		else if (i == 4) {
			e = n;
		}
		else if (i == 5) {
			f = n;
		}
	}
	if (a > d) {
		cout << 1;
	}
	else if (a < d) {
		cout << -1;
	}
	else if (a == d) {
		if (b > e) {
			cout << 1;
		}
		else if (b < e) {
			cout << -1;
		}
		else if (b == e) {
			if (c > f){
				cout << 1;
			}
			else if (c < f) {
				cout << -1;
			}
			else if (c == f) {
				cout << 0;
			}
		}
	}


}





