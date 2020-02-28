#include <iostream>

using namespace std;
int A[60];
int n;

bool solve(int i, int m) {
    if(m == 0) {
        return true;
    }
    if(i >= n) {
        return false;
    }
    int res = solve(i+1, m) || solve(i+1, m-A[i]);
    return res;
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