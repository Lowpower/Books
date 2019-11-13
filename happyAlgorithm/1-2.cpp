#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int prime(int n) {
	if(n <=1) {
		return 0;
	}
	if(n ==2 ) {
		return 1;
	}
	for(int j = 2; j <= static_cast<int>(sqrt(static_cast<double>(n))); j++) {
		if(!(n%j)) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int i,n;
	for(i = 4; i <= 2000; i+=2) {
		for(n =2; n < i; n++) {
			if(prime(n)) {
				if(prime(i-n)) {
					cout << i << "=" << n <<"+" << i-n << endl;
					break;
				}
			}
		}
		if(n == i) {
			cout << "error" << endl;
		}
	}
	return 0;
}
