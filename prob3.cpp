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
	int term = -1;
	bool min = false;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a >= 0) {
			if (!min || term > a) {
				term = a;
			}
			min = true;  // �ּ� �ϳ��� ����� �ԷµǾ���
		}

	}
	cout << term;





	}





