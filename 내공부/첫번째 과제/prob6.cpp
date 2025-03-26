/*
키보드로 부터 2개 이상의 정수들을 연속해서 입력받는다. -1은 입력의 끝을 의미한다 (즉, -1 자체는
입력된 정수로 간주하지 않는다.) 입력된 정수들 중에서 극소값(local minima)의 개수를 카운트하여
출력하라. 여기서 극소값이란 바로 직전에 입력된 정수보다 작거나 같고, 바로 다음에 입력된 정수보다
도 작거나 같은 수를 의미한다. 단, 첫 번째 정수는 2번째 정수보다 작거나 같으면 극소값으로 간주하
고, 마지막 정수는 바로 이전의 정수보다 작거나 같으면 극소값으로 간주한다.
---알고리즘---

while(true) // for대신 while을 쓰는이유는 계속 반복할거라서
정수를 받는 n
첫번쨰 반복일떄 n일때 +1 그리고 왼쪽 변수에 저장
두번째 반복일때 n+1 일때 비교군 변수에 저장
세번째 반복일때 n+2 일때 오른쪽 변수에 저장
그다음 n+2는 비교군에 저장
n+1은 왼쪽비교군에 저장
-1나올떄 까지 반복...





*/

#include <iostream>

using namespace std;;

int main() {
	int n, left, right, cen;
	int count = 0;
	int arr[100];
	for (int i = 0; ;i++) {
		cin >> n;
		arr[i] = n;
		if (n == -1) {
			break;
		}

	}
	if (arr[0] < arr[1]) {
		count = count + 1;

	}
	for (int i = 0; ; i++) {
		if (arr[i] <= arr[i + 1] && arr[i] >= arr[i - 1]) {
			count = count + 1;
		}
		if (arr[i] == -1) {
			break;
		}

	}
	cout << " 몇 개? " << count;

}





