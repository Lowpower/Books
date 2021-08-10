#include <iostream>

using namespace std;
int A[60];
bool dp[100][100];
int n;

bool solve(int i, int m) {
    if(dp[i][m]) {
        return dp[i][m];
    }
    if(m == 0) {
        dp[i][m] = true;
    } else if (i >= n) {
        dp[i][m] = false;
    } else if (solve(i+1, m)) {
        dp[i][m] = true;
    } else if (solve(i+1, m-A[i])) {
        dp[i][m] = true;
    } else {
        dp[i][m] = false;
    }
    return dp[i][m];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >>A[i];
    }
    int q, M;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> M;
        if(solve(0, M)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }
    return 0;
}