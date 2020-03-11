#include <iostream>

using namespace std;
constexpr int MAX = 10000;
constexpr int NIL = -1;

typedef struct Node {
    int p, l,  r;
};
Node T[MAX];
int n, D[MAX];

void print() {

}

int rec(int u, int p) {
    return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        T[i].p = T[i].l = T[i].r = NIL;
    }
    int v, d, c;
    for (int i = 0; i < n; i++) {
        cin >> v >> d;
        for (int j = 0; j < d; j++) {
            cin >> c;
            if(j == 0) {
                T[v].l = c;
            } else {
                T[v].r = c;
            }
            l = c;
            T[c].p = v;
        }
    }
    for (int i = 0; i < n; i++) {
        if(T[i].p == NIL) {
            r = i;
        }
    }
    rec(r, 0);
    for (int i = 0; i < n; i++) {
        print(i);
    }
    return 0;
}