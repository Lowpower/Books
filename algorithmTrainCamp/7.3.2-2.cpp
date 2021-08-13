#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 1000;
int dp[maxn];
int a[maxn][maxn];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    for (int j = i; j >=1; j--) {
      scanf("%d", &a[i][j]);
    }
  }
  memset(dp, 0, sizeof(dp));
  dp[1] = a[1][1];
  for(int i = 2; i<= n; i++) {
    for (int j = i; j <= i; j++) {
      dp[j] = a[i][j] + max(dp[j], dp[j-1]);
    }
  }
  int ans = 0;
  for (int j = 1; j<= n; j++) {
    ans = max(dp[j], ans);
  }
  return 0;
}