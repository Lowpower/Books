#include <iostream>
#include <stack>
using namespace std;

static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int dis[N];
int n, M[N][N];
int color[N];
int d[N], f[N], nt[N];

int next(int u) {
    for (int v = nt[u]; v < n; v++) {
        nt[u] = v+1;
        if(M[u][v]) {
            return v;
        }
    }
    return -1;
}

void dfs_visit(int r) {
    for (int i = 0; i < n; i++) {
        nt[i] = 0;
    }
    stack<int> S;
    S.push(r);
    color[r] = GRAY;
    while(!S.empty()) {
        int u = S.top();
        int v = next(u) {
            if(v != -1) {

            }
        }
    }
}

void dfs() {
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
    }
    for (int u = 0; u < n; u++) {
        if (color[u] == WHITE) {
            dfs_visit(u);
        } 
     }
     for (int i = 0; i < n; i++) {
         cout << i+1 << " " << d[i] << " " << f[i] << endl;
     }
}

int main() {
    int u, k, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            cin >> v;
            v--;
            M[u][v] = i;
        }
    }
    dfs();
    return 0;
}