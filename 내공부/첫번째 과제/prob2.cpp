/*
* a : 첫번째 항
* r : 공비
* n : 더하는 갯수
* 등비수열 공식 : a(r^n-1)/ r - 1





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
	x = (double)a * (1 - rn);  // 올바른 공식 적용
	y = 1 - r;                 // 분모도 수정
	double sum = x / y;
	printf("%0.3f", sum);
	
	}





