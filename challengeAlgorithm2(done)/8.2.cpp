#include <iostream>
using namespace std;

const int MAX = 10000;
const int NIL = -1;

struct Node {
    int parent, left, right;
};
Node T[MAX];
int D[MAX];
int H[MAX];

void setDepth(int u, int d) {
    if(u == NIL) {
        return;
    }
    D[u] = d;
    setDepth(T[u].left, d+1);
    setDepth(T[u].right, d+1);
}

void setHeight(int u) {
    int h1 = 0;
    int h2 = 0;
    if(T[u].left != NIL) {
        h1 = setHeight(T[u].left) + 1;
    }
    if(T[u].right != NIL) {
        h2 = setHeight(T[u].right) + 1;
    }
    return H[u] = max(h1, h2);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        T[i].parent = NIL;
    }
    return 0;
}