#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 100;

bool isAlnumString(const string& str) {
	for (char c : str) {
		if (!isalnum(c)) return false;
	}
	return true;
}

int main() {
	string str;
	vector<string> a, b;

	while (true) {
		cin >> str;
		if (str == "exit") {
			break;
		}
		a.push_back(str);
	}

	string answer;
	for (int s = 0; s < a.size(); s++) {
		if (isAlnumString(a[s])) {
			b.push_back(a[s]);
		}
	}

	// 예시로 b의 내용을 출력
	for (const string& s : b) {
		cout << s << " ";
	}
}
