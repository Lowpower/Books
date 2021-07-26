#include <iostream>
#include <vector>
using namespace std;

void print_permutation(vector<int>& A, int cur) {
    if(cur == A.size()) {
        for (auto i: A) {
            cout << i;
        }
        cout << endl;
    } else {
        for (int i = 1; i <= A.size(); i++) {
            int ok = 1;
            for(int j = 0; j < cur; j++) {
                if(A[j] == i) {
                    ok = 0;
                }
                if(ok) {
                    A[cur] = i;
                    print_permutation(A, cur +1);
                }
            }
        }
    }

}

int main() {
    vector<int> A{1, 2, 3, 4};
    print_permutation(A, 0);
    return 0;
}