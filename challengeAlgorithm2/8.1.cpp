#include <iostream>

using namespace std;
constexpr int MAX = 10000;
constexpr int NIL = -1;

 struct Node {
    int p, l,  r;
};
Node T[MAX];
int n, D[MAX];

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";
    if (T[u].p == NIL) {
        cout << "root, ";
    } else if (T[u].l == NIL) {
        cout << "leaf, ";
    } else  {
        cout << "internal node, ";
    }
    cout << "[";
    for (int i = 0, c = T[u].l; c !=NIL; i++, c = T[c].r) {
        if(i) {
            cout << ", ";
        }
        cout << c;
    }
    cout << "]" << endl;
}

int rec(int u, int p) {
    D[u] = p;
    if(T[u].r != NIL) {
        rec(T[u].r, p);
    }
    if(T[u].l != NIL) {
        rec(T[u].l, p +1);
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        T[i].p = T[i].l = T[i].r = NIL;
    }
    int v, d, c, l;
    for (int i = 0; i < n; i++) {
        cin >> v >> d;
        for (int j = 0; j < d; j++) {
            cin >> c;
            if(j == 0) {
                T[v].l = c;
            } else {
                T[l].r = c;
            }
            l = c;
            T[c].p = v;
        }
    }
    int root = 0;
    for (int i = 0; i < n; i++) {
        if(T[i].p == NIL) {
            root = i;
        }
    }
    rec(root, 0);
    for (int i = 0; i < n; i++) {
        print(i);
    }
    return 0;
}