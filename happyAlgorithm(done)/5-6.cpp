#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1e7;
const int N = 100;

int main() {
    int n, m;
    int x[N]; // 记录当前路径
    int bestx[N]; // 记录当前最优路径
    int g[N][N];
    int u, v, w;
    cin >> n;
    for (int i = 0 ; i <= n; i++) {
        for(int j = i ; j <= n; j++) {
            g[i][j] = g[j][i] = INF;
        }
    }
    for (int i = 0; i <= n; i++) {
        x[i] = i;
        bestx[i] = 0;
    }
    cin >> m;
    for (int i = 0; i <= m; i++) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    return 0;
}