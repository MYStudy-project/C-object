#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX = 1000;
int main() {
	ifstream infile("input34.txt");
	string lines[MAX];
	string line;
	int n = 0;
	while (getline(infile, line))
		lines[n++] = line;

	infile.close();
	for (int i = 0; i < n; i++)
		cout << lines[i] << endl;
	return 0;
}