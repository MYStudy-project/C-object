/*
���� ���� ���� n�� �Է¹ް� �̾ n���� ������ Ű����� ���� �Է¹޴´�. �Էµ� ������ �߿���
���� �ƴ� ������ �߿��� �ּҰ��� ã�Ƽ� ����ϴ� ���α׷��� �ۼ��϶�. �׷� ���� �������� ����
��� -1�� ����϶�.



*/

#include <iostream>

using namespace std;;

int main() {
	int n;
	cin >> n;
	int min = 0;
	int max = 0;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (min >= a) {
			min = a;

		}
		else if (max <= a) {
			max = a;
		}
		cout << max - min << " ";

	}





	}





