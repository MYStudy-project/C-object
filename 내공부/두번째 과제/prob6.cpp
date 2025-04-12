#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

int main() {
	fstream file("sample.txt");
	string word;
	vector<string> wordcollection;
	while (file >> word) { //특수문자 없애는 연습해봅시다.
		wordcollection.push_back(word);

	}
	int n = wordcollection.size();
	int min_location;
	for (int i = 0; i < n; i++) {
		string minarr = wordcollection[i];
		min_location = i;
		for (int j = i + 1; j < n; j++) {
			if (minarr > wordcollection[j]) {
				minarr = wordcollection[j];
				min_location = j;
			}
		}
		for (int k = min_location; k > i; k--) {
			swap(wordcollection[k], wordcollection[k - 1]);
		}
	}

	for (int i = 0; i < wordcollection.size(); i++) {
		cout << wordcollection[i] << endl;
	}
}