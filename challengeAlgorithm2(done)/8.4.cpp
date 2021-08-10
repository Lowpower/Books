#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> post;
vector<int> pre;
vector<int> in;
int pos = 0;

void rec(int l, int r) {
    if (l >= r) {
        return;
    }
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    rec(l, m);
    rec(m+1, r);
    post.push_back(root);
}

void solve() {
    rec(0, pre.size());
    for (int i = 0; i < pre.size(); i++) {
        if (i) {
            cout << " ";
        }
        cout << post[i];
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        pre.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        cin >> k;
        in.push_back(k);
    }
    solve();
    return 0;
}