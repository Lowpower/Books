#include <iostream>

using namespace std;
static const int MAX = 100;
static const int INFTY = 0x3f3f3f;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n, M[MAX][MAX];

void dijkstra() {

}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = INFTY;
        }
    }
    int k, c, u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k;j++) {
            cin >> v >> c;
            M[u][v] = c;
        }
    }
    dijkstra();
    return 0;
}