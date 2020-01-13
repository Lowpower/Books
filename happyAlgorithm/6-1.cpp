#include <iostream>

using namespace std;
const int N;

class Node {
public:
    int cp, rp;
    int rw;
    int id;
    bool x[N];
    Node () {memset(x, 0, sizeof(x));}
    Node (int _cp, int _rp, int _rw, int _id)cp(_cp), rp(_rp), rw(_rw), id(_id) {}
};

struct Goods {
    int value;
    int weight;
}goods[N];

int main() {
    int n, w;
    cin >> n;
    cin >> w;
    int bestp = 0;
    int sumw = 0;
    int sumv = 0;
    for(int i = 1; i <= n; i++) {
        cin >> goods[i].weight >> goods[i].value;
        sumw += goods[i].weight;
        sumv += goods[i].value;
    }
    if(sumw <= w) {
        bestp = sumv;
        cout << "putit all, best" << bestp << endl;
        return 0;
    }
    bool bestx[N];
    cout << "best:" << endl;
    for(int i = 1; i <= n; i++) {
        if(bestx[i]) {
            cout << i << "  ";
        }
    }
    return 0;
}