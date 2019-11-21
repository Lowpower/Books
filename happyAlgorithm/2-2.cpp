#include <algorithm>
#include <iostream>

using namespace std;
const int M = 1000005;

struct three {
	double w;
	double v;
	double p;
}s[M];

int main() {
	int n;
	double m;
	cin>> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i].w >> s[i].v;
		s[i].p = s[i].v/s[i].w;
	}
	sort(s, s+n, [](three a, three b){return a.p>b.p;});
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		if(m > s[i].w) {
			m-=s[i].w;
			sum += s[i].v;
		} else {
			sum += m*s[i].p;
			break;
		}
	}
	cout << sum << endl;
	return 0;
}
