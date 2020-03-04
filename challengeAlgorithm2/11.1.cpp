#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int F[50];
    F[0] = F[1] = 1;
    for (int j = 2; j <= n; j++) {
        F[j] = F[j-1] + F[j-2];
    }
    cout << F[n] << endl;
    return 0;
}