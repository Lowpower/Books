#include <iostream>

using namespace std;
int n, k;
const int MAX = 100000;
long long T[MAX];

int check(long long p) {
    int i;
    for (int j = 0; j < k; i++) {
        long long s = 0;
        while(s + T[i] <= p) {
            s+= T[i];
            i++;
            if(i == n) {
                return n;
            }
        }
    }
    return i;
}

long long solve() {
    long long left = 0;
    long long right = 1e5*1e5;
    long long mid;
    while(right - left > 1) {
        mid = (left + right) /2;
        int v = check(mid);
        if(v >= n) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    long long ans = solve();
    cout << ans << endl;
    return 0;
}