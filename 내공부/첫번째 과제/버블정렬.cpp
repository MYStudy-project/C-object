#include <iostream>

using namespace std;

int main() {
	int arr[7] = { 5, 6, 2, 1, 4, 8, 3 };
	int temp, min, max;
	temp = 0;
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 6; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}

}
	
