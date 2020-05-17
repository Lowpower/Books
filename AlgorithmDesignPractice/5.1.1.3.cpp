#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f;
const int maxn = 10000;
struct Seg{
    int le, ri, ind;
    bool operator < (const Seg y) const {
        return ri < y.ri;
    }
}a[maxn+5];
int n;
int main() {
    while(~scanf("%d", &n)&& n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].le, &a[i].ri);
            a[i].ind = i;
        }
        sort(a+1, a+1+n);
        int now = a[1].ri + 1;
        cout << a[1].ind;
        for (int i =2; i <= n; i++) {
            if(a[i].le < now) {
                continue;
            }
            now = a[i].ri + 1;
            cout << " " << a[i].ind
        }
        cout << endl;
    }
}