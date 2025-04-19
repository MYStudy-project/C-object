#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

string findpre(vector<string>& prefiex);


int main() {
	int n;
	cin >> n;
	vector<string> str;
	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		str.push_back(word);
	}
	string c = findpre(str);
	cout << c;
	

}

string findpre(vector<string>& prefiex) {
	string a = prefiex[0];
	string b;
	for (int i = 1; i < prefiex.size(); i++) {
		for (char c : prefiex[i]) {
			if (find(prefiex[0].begin(), prefiex[0].end(), c) != prefiex[0].end() && b.find(c) == string::npos) {
				b = b + c;
			}
		}
	}
	return b;
 }


