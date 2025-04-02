#include <iostream>

using namespace std;

int main() {

	int cot;
	int year1;
	int year2;
	int month1;
	int month2;
	int date1;
	int date2;

	for (cot = 0; cot < 6; cot++)
	{
		int a;
		cin >> a;
		if (cot == 0) {
			year1 = a;
		}
		else if (cot == 1) {
			month1 = a;
		}
		else if (cot == 2) {
			date1 = a;
		}
		else if (cot == 3) {
			year2 = a;
		}
		else if (cot == 4) {
			month2 = a;
		}
		else if (cot == 5) {
			date2 = a;
		}


	}
	if (year1 == year2) {
		if (month1 == month2) {
			if (date1 == date2) {
				cout << 0;

			}
			else if (date1 > date2) {
				cout << 1;
			}
			else {
				cout << -1;
			}

		}
		else if (month1 > month2) {
			cout << 1;
		}
		else {
			cout << -1;
		}
	}
	else if (year1 > year2) {
		cout << 1;
	}
	else {
		cout << -1;
	}

}