#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int counting(string& getline);


int main() {
	ifstream infile("sample_lines.txt");
	string line;
	vector<string> lines;
	;
	while(getline(infile, line)) {
		lines.push_back(line);
	}
	int n = lines.size();
	int b;
	for (int i = 0; i < n; i++) {
		string getlines = lines[i];
		int wordcount = counting(getlines);
		cout << lines[i] << ":" << wordcount << endl;
	}

}

int counting(string& getline) {
	int count = 0;
	bool inWord = false;

	for (char c : getline) {
		if (!isspace(c)) {
			if (!inWord) {
				count++;
				inWord = true;
			}
		}
		else {
			inWord = false;
		}
	}
	return count;


}
