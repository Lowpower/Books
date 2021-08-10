#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A;
static const int MAX = 1000;
static const int VMAX = 10000;
int n;
int s = VMAX;

int solve(int s) {
    int ans = 0;
    vector<bool> V(MAX);
    vector<int> B(n);
    vector<int> T(VMAX +1);
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
        V[i] = false;
    }
    sort(B.begin(), B.end());
    for(int i = 0; i < n; i++){
        T[B[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (V[i]) {
            continue;
        }
        int cur = i;
        int m = VMAX;
        int S = 0;
        int an = 0;
        while(1) {
            V[cur] = true;
            an++;
            int v = A[cur];
            m = min(m, v);
            S += v;
            cur = T[v];
            if(V[cur]) {
                break;
            }
        }
        ans += min(S + (an - 2)*m, m + S +(an +1) *s);
    }
    return ans;
}

int main(){
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        A.push_back(tmp);
        s = min(s, A[i]);
    }
    int ans = solve(s);
    cout << ans << endl;
    return 0;
}