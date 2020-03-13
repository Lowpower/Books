#include <iostream>
using namespace std;

const int MAX = 10000;
const int NIL = -1;

struct Node {
    int parent, left, right;
};
Node T[MAX];

void sserDepth() {
    
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        T[i].parent = NIL;
    }
    return 0;
}