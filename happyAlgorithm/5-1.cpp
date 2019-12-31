#include <iostream>
#include <algorithm>

using namespace std;

const int M = 105;
double w[M], v[M];
bool bestx[M];

void Backtrack(int t, int n, double W) {
    if (t > n) {
        for (int i = 1; i <= n; i++) {
            bestx[j] = x[j];
        }
        bestp = cp;
        return;
    }
    if (cw + w[t] <= W)
}

void Knapsack(double W, int n) {
    double cw = 0;
    double cp = 0;
    double bestp = 0;
    double sumw = 0.0;
    double sumv = 0.0;
    for (int i =1; i <= n; i++) {
        sumv += v[i];
        sumw += w[i];
    }
    if(sumw <= W) {
        bestp  = sumv;
        cout << "bestp = " << bestp << endl;
        cout << "complete" << endl;
    }
    Backtrack(1, n, W);
}

int main() {
    int n, W;
    cin >> n;
    cin >> W;
    for (int i= 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    Knapsack(W, n);
    return 0;
}