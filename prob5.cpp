/*
 2개의 날짜를 입력받은 후 그 중 첫 번째 날짜가 더 이르면 -1, 두 번째 날짜가 더 이르면 1, 두 날짜
가 동일하면 0을 출력하는 프로그램을 작성하라. 각각의 날짜는 년, 월, 일을 나타내는 3개의 정수로
주어진다. 날짜의 유효성을 체크할 필요는 없다.



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





