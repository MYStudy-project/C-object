/*
먼저 양의 정수 n을 입력받고 이어서 n개의 정수를 키보드로 부터 입력받는다. 입력된 정수들 중에서
음이 아닌 정수들 중에서 최소값을 찾아서 출력하는 프로그램을 작성하라. 그런 값이 존재하지 않을
경우 -1을 출력하라.



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
			min = true;  // 최소 하나라도 양수가 입력되었음
		}

	}
	cout << term;





	}





