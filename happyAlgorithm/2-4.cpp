#include <cstdio>
#include <iostream>
#include <stack>
#include <climits>

using namespace std;
const int INF = INT_MAX;
const int N = 100;

int map[N][N];

void Dijkstra(int u) {
}

int main() {
	int n, m, st;
	cin >> n;
	cin >> m;
	for (int i = 1; i <=n; i++) {
		for(int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}
	while(m--) {
		cin >>u >> v >> w;
		map[u][v] = min(map[u][v], w);
	}
	cin >> st;
	Dijkstra(st);
	cout << "go" << st;
	for (int i = 0; i<= n; i++) {
		cout<< "xiaoming " << st << "-" << "will going" << i << endl;
		if(dist[i] == INF) {
			cout << "no way" << endl;
		} else {
			cout << "nearby:" << dist[i] << endl;
		}
	}
	return 0;
}
