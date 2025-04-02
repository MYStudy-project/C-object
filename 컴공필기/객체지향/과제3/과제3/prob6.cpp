#include <iostream>

using namespace std;

int main() {
	cout << "NÀ» ÀÔ·Â" << endl;

	int a;
	bool b = true;
	int cen;
	int max;
	int cot = 0;
	bool index = true;

	while (b == true) {

		cin >> a;

		if (index == true && a >= 0) {
			cen = a;
			index = false;
			cot++;

		}
		else if(index != false && cen <= a) {
			max = a;
			if (max >= a) {


			}


		}
	}
	cout << cot << endl;

}