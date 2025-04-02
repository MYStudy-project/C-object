#include <iostream>

using namespace std;

int main() {
	int arr[5] = { 5, 6, 2, 1, 4 };
	for (int i = 0; i < 5; i++) {
		int min = arr[i];
		int mincout = i;
		for (int j = i + 1; j < 5; j++) {
			if (min > arr[j]) {
				min = arr[j];
				mincout = j;
			}
			
		}
		swap(arr[i], arr[mincout]);
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";;
	}



}
	
