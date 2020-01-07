#include <iostream>
#include <vector>

using namespace std;
const int M = 105;
int n;
int x[M];
int countn = 0;

bool Place(int t) {}

void Backtrack(int t) {
    if (t > n) {
        countn++;
        for(int i = 1; i <= n; i++) {
            cout << x[i] << "   ";
        }
        cout << endl;
        cout << "------------" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            x[t] = 1;
            if (Place(t)) {
                Backtrack(t + 1);
            }
        }
    }
};

int main() {
    cin >> n;
    Backtrack(1);
    cout << countn << endl;
    return 0;
}