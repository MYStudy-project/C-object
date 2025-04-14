#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
	int n,a;
	int count = 0;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> a;
		count++;
		for (int j = 0; j < count; j++) {
			if (a != arr[j]) {
				arr.push_back(a);
			}
		}
	}
	cout << arr.size();
}
