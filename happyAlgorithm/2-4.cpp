#include <cstdio>
#include <iostream>
#include <stack>
#include <climits>

using namespace std;
const int INF = INT_MAX;
const int N = 100;

int map[N][N];

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <=n; i++) {
		for(int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}
	return 0;
}
