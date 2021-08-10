#include <iostream>
using namespace std;
const int N = 1000;

int main() {
    int n;
    cin >> n;
    int M[N][N];
    for (int i  = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }
    int u, k, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(j) {
                cout << " ";
            }
            cout << M[i][j];
        }
        cout << endl;
    }
    return 0;
}