#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    public:
    int location;
    int p, l, r;
    Node(){}
};

class Point {
public:
    int id, x, y;
    Point(){}
    Point(int id, int x, int y):id(id), x(x), y(y) {}
    bool operator < (const Point &p) const {
        return id < p.id;
    }
    void print() {
        printf("%d\n", id);
    }
};

int N;
static const int MAX = 1000000;
static const int NIL = -1;
Node P[MAX];
Point P[MAX];
int np;

bool lessX (const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

bool lessY (const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}


int main() {
    int x, y;
    scanf("%d", N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);

    }
    return 0;
}