#include <iostream>
#include <algorithm>

const int N = 1000005;
using namespace std;
double w[N];

int main() {
	double c;
	int n;
	cin >> c>> n;
	for(int i = 0; i  < n;i++) {
		cin>>w[i];
	}
	sort(w, w+n);
	double temp = 0.0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		temp +=w[i];
		if(temp <= c) {
			ans++;
		}else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
