#include <iostream>

using namespace std;

const int N = 1002;
int c[N][N], b[N][N];

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
		for(int i = 0; i <= len1; i++) {
			for(int j = 1; j <= len2; j++) {
				if(s1[i-1] == s2[j-1]) {
					c[i][j] = c[i-1][j-1] + 1;
					b[i][j] = 1;
				}
			}
		}
	};
	LCSL();
	cout << c[len1][len2] << endl;
	auto print = [&](int i, int j) {
	};
	print(len1, len2);
	return 0;
}
