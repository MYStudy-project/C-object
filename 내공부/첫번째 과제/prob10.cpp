#include <iostream>
#include <string>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <cstdlib>  // abs()


using namespace std;
int main() {
	int arr[100];
	int n,push;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> push;
		arr[i] = push;
	}
	int min, compa, result;
	cin >> compa;
	min = abs(compa - arr[0]);
	result = arr[0];
	for (int i = 0; i < n; i++) {
		if (abs(compa - arr[i]) < min) {
			min = abs(compa - arr[i]);
			result = arr[i];
		}
	}

	cout << result;
}



