#include <iostream>

using namespace std;

void init(int n) {
  for(int i = 1; i <= n; i++) {
    fa[i] = i;
  }
}

int Find(int x) {
  if(x != fa[x]) {
    fa[x] = Find(fa[x]);
  }
  return fa[x];
}

void Union(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if (a != b) {
    fa[b] = a;
  }
}