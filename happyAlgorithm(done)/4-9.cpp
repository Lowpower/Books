#include <iostream>

using namespace std;

const int M = 105;
const int maxn = 10005;
int c[M][maxn];
int w[M], v[M];
int x[M]; // 第i个物品是否放入购物车

int main() {
    int n, W;
    cin >> n; // n个物品
    cin >> W; // w容量
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i]; // 每个物品的个数和容量
    }
    for (int i = 0; i < n; i++) {
        c[i][0] = 0;
    }
    return 0;
}