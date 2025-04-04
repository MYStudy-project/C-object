﻿/*
1693년에 Samuel Pepys는 뉴튼에게 “주사위를 6번 던져서 적어도 한 번 1이 나오는 것”과 “주사위를
12번 던져서 적어도 두 번 1이 나오는 것” 중 어느 쪽이 일어날 확률이 더 높은지 질문하였다. 이 질문
에 대한 답을 실험을 통해 알아내는 프로그램을 작성하라. 즉 T=1,000,000번의 실험을 하여 두 사건이
일어난 경우의 수를 각각 카운트하는 프로그램을 작성하라. (6번 던져서 적어도 1번 1이 나오는 사건
의 확률은 1-(5/6)6 ≃ 0.6651이고, 12번 중 적어도 2번 1이 나오는 사건의 확률은 1-(5/6)12-2(5/
6)11 ≃ 0.618667이다. 대략 이 확률에 근접하는 실험 결과가 나오면 정답이다.)



*/

#include <iostream>
#include <cmath>
#include <cstdlib>  // rand(), srand() 포함
#include <ctime>    // time() 포함

using namespace std;;

int main() {
	srand(time(0));
	int sixcount = 0;


	for (int i = 0; i < 1000000; i++) {
		for (int i = 0; i < 6; i++) {
			int a = rand() % 6 + 1;
			if (a != 1) {
				sixcount++;
				}
		}

	}
	cout << 1 - ((double)sixcount / 1000000);

}





