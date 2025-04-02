#include <iostream>

using namespace std;

int main() {
	cout << "NÀ» ÀÔ·Â" << endl;
	
	int n;
	cin >> n;

	int a;
	int min;
	int max;
	bool index = true;

	for (int i = 0; i < n; i++) {

		cin >> a;

		if (index == true && a >= 0) {

			min = a;
			max = a;
			index = false;

		}
		else if (index == true && a <= 0) {
			min = a;
			max = a;
			index = false;


		}
		else if (index == false) {
			if (min > a) {
				min = a;


			}
			else if (min < a) {

				if (max < a) {
					max = a;
					


				}


			}



		}
		int sum;
		sum = max - min;
		cout << sum;
	}

}