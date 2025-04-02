#include <iostream>

using namespace std;

int main() {
	int arr[7] = { 5, 6, 2, 1, 4, 8, 3 };
	int temp, min, max;
	for (int a = 0; a < 7; a++) {
		int minarr = arr[a];
		int min = a;
		for (int i = a; i < 7; i++) {
			if (minarr > arr[i]) {
				minarr = arr[i];
				min = i;
			}
		}
		for (int j = a; j < min; j++) {
			arr[min - j],arr[min - j - 1];
		}
		arr[a] = minarr;
		
	}
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}

}
	
