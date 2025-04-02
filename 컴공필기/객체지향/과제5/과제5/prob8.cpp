#include <iostream>

using namespace std;

int main() {

	int a = 0;
	int b[5];
	b[0] = 13;
	b[1] = 1;
	b[2] = 3;
	b[3] = 161;
	b[4] = 2;

	for (int i = 0; i < 5 / 2; i++) {
		double temp = b[i];
		b[i] = b[5 - 1 - i];
		b[5 - i - 1] = temp;
	}

	for (int j = 0; j < 5; j++) {
		cout << b[j] << endl;


	}

}
