#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

int main() {
	string a;
	vector<string> str;
	bool b = true;
	while (true) {
		cin >> a;

		if (a == "exit") {
			b = false;
			break;
		}
		for (int i = 0; i < str.size(); i++) {
			if (a == str[i]) {
				str.push_back("dupblicate");
				for (int j = 0; j < str.size(); j++) { // size()는 비어있으면 작동을 안한다. 그래서 무한루프 걸린거임
					cout << str[j];
				}
			}
			else {
				str.push_back(a);
				for (int j = 0; j < str.size(); j++) {
					cout << str[j];
				}
			}
		}

	}
}