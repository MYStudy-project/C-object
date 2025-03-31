#include <iostream>
#include <string>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <cstdlib>  // abs()


using namespace std;
int main() {
	int arr[100];
	int n,a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[i] = a;
	}
	int leader = arr[0];
	int arr2[100];
	arr2[0] = leader;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (leader <= arr[i]) {
			arr2[j] = arr[i];
			j++;
			leader = arr[i];
		}
	}
	int count = 0;
	cout << j << ":";
	for (int i = 0; i < j; i++) {
		cout << arr2[i] << " ";
	}


}



