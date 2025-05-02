#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Box{
	int capacity;
public:
	Box() {}
	Box(double capacity) {
		this->capacity = capacity;
	}
	bool operator<(Box b) {
		return b.capacity < this->capacity ?
		true : false;
	}
};
int main() {
	Box b1(10);
	Box b2 = Box(14);
	if (b1 < b2)
		cout << "B1's capacity is small";
	else
		cout << "B2's capacity is small";
	return 0;
}