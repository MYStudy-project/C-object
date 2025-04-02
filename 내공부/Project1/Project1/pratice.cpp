#include <iostream>

using namespace std;

int main() {
	int arr[5] = { 5,6,2,8,1 };
	int n = arr[0];
	int i = 0;
	int temp = 0;
	while (true) {
		int j = i;
		temp = n;
		for (j; j < 5; j++) {
			if (n > arr[j]) {
				n = arr[j];

			}
		}
		arr[i] = n;
		i++;
		n = arr[i];
		if (i > 5) {
			break;
		}

	}
	for (int j = 0; j < 5; j++) {
		cout << arr[j] << " ";
		}
}
	
