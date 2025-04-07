#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;



int main()
{
	string words[MAX], str;
	int n, k;
	k = 0;
	bool a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		a = true;
		for (int j = 0; j < k; j++) {
			if (words[j] == str) {
				a = false;
				break;
			}
		}
		if (a == true) {
			words[k++] = str;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (words[j] > words[j + 1]) {
				swap(words[j], words[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << words[i] << " ";
	}



}