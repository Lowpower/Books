#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int M = 10000;

int x, n, i;
int s[M];

int BinarySearch (int n, int s[], int x) {
	int low = 0;
	int high = n-1;
	while(low <= high) {
		int middle = (low+high)/2;
		if(x == s[middle]) {
			return middle;
		} else if (x < s[middle]) {
			high = middle-1;
		} else {
			low = middle+1;
		}
	}
	return -1;
}

int main() {
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			cin>>s[i];
		}
		sort(s, s+n);
		for(i = 0; i < n; i++) {
			cout << s[i] << " ";
		}
		cout << endl;
		cin >> x;
		i = BinarySearch(n, s, x);
		if(i == -1) {
			cout << "not found" << endl;
		} else {
			cout << "found:" << i+1 << endl;
		}
	}
	return 0;
}
