#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 +10;
using pii = std::pair<int, int>;

int l[N], r[N];
pii a[2*N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int left, right;
            scanf("%d%d",&left, &right);
            a[2*i-1] = pii(left, 1);
            a[2*i] = pii(right, -1);
        }
        sort(a+1, a+2*n+1);
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        int num = 0, ans = 0;
        for (int i = 1; i <= 2*n; i++) {
            if(a[i].second == 1) {
                num++;
                if(l[num] == -1) {
                    l[num] = r[num] = a[i].first;
                }
                ans = max(ans, num);
            } else {
                r[num] = a[i].first;
                num--;
            }
        }
        int64_t sum = 0;
        for(int i = 1; i <= ans; i++) {
            sum += r[i] - l[i];
        }
        printf("%d %lld\n", ans, sum);
    }
    return 0;
}