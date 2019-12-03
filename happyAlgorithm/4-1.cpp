#include <iostream>

using namespace std;

void print(int i, int j) {
}

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for (int i = 0; i <=len1; i++) {
		c[i][0] = 0;
	}
	for(int j = 0 ; j <= len2; j++) {
		c[0][j] = 0;
	}
	auto LCSL = [&] (){
	};
	LCSL();
	cout << c[len1][len2] << endl;
	auto print = [&](int i, int j) {
	};
	print(len1, len2);
	return 0;
}
