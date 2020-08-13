#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_N = 100;
bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n) {
    if(pos == n) {
        for(int i = 0; i < n; i++) {
            cout << perm[i];
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            perm[pos] = i;
            used[i] = true;
            permutation1(pos+1, n);
            used[i] = false;
        }
    }
    return;
}

int main() {
    permutation1(0, 3);
    return 0;
}