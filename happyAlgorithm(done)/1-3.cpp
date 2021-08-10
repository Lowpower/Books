#include <iostream>

using namespace std;

int Fib(int n) {
	int s1, s2;
	if(n<1) {
		return -1;
	}
	if(1 == n || 2 == n) {
		return 1;
	}
	s1 =1;
	s2 =1;
	for(int i = 3; i < n; i++) {
		s2 = s1+s2;
		s1 = s2 -s1;
		cout <<"s1:" << s1 << endl;
		cout <<"s2:" << s2 << endl;
	}
	return s2;
}

int main() {
	Fib(30);
	return 0;
}
