#include <iostream>
#include <string>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()

using namespace std;
int main() {
	srand(std::time(0));  
	int t = 1000000;
	int i;
	bool dicebool6 = false;
	int dicebool12 = 0;
	int count6 = 0;
	int count12 = 0;
	for (i = 0; i < t; i++) {
		for (int j = 0; j < 6; j++) {
			int dice = rand() % 6 + 1;
			if (dice == 1) {
				dicebool6 = true;
			}

		}
		if (dicebool6) {
			dicebool6 = false;
			count6++;

		}
		for (int j = 0; j < 12; j++) {
			int dice = rand() % 6 + 1;
			if (dice == 1) {
				dicebool12++;
			}

		}
		if (dicebool12 >= 2) {
			count12++;

		}
		dicebool12 = 0;
	}
	double a,b;
	a = (double)count6 / t;
	b = (double)count12 / t;
	cout << a << endl;
	cout << b;

}



