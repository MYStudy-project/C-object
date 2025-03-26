/*
피보나치는 더하고 더하는거 잖아



*/

#include <iostream>

using namespace std;;

int main() {
	int fn_1 = 1;
	int fn_2 = 1;
	int fn;
	
	int n;
	cin >> n;

	for (int i = 1 ; i < n ; i++) {
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;

	}
	cout << fn << endl;




}