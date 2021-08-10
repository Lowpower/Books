typedef unsigned long long LL;
constexpr int MAXN = 1000000;
int fn[MAXN + 1];

void solve() {
  fn[1] = 0;
  fn[2] = 1;
  fn[3] = 2;
  for (int i = 4; i <= MAXN; i++) {
    fn[i] = fn[i-2] + fn[i-1];
  }
}