/*
* a : ù��° ��
* r : ����
* n : ���ϴ� ����
* ������ ���� : a(r^n-1)/ r - 1





*/

#include <iostream>

using namespace std;;

int main() {
	int n;
	int a = 1;
	double r = -0.5;
	cin >> n;
	double x, y;
	double rn = -0.5;

	for (int i = 0; i < n; i++) {
		rn = r * rn;
	}
	x = (double)a * (1 - rn);  // �ùٸ� ���� ����
	y = 1 - r;                 // �и� ����
	double sum = x / y;
	printf("%0.3f", sum);
	
	}





