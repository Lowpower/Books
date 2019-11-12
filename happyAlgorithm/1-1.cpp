#include <iostream>
using namespace std;

int main() {
	int x, y,z,count = 0;
	cout << "men, women children" << endl;
	cout << "..............." << endl;
	for(x = 1; x < 9; x++) {
		y = 20- 2*x;
		z = 30 - x - y;
		if(3*x+2*y+z == 50) {
			cout << ++count << "	" << x << " "<< y  << " "<< z << endl;
		}
	}
	return 0;
}
