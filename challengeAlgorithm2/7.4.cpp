#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A;
    vector<int> B;
    int tmp;
    int max = -1;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        A.push_back(tmp);
        if(tmp > max) {
            max = tmp;
        }   
    }
    B.reserve(max+1);
    for (auto v : A) {
        B[v]++;
    }
    for (int i = 1; i < B.size(); i++) {
        B[i] += B[i-1];
    }
    vector<int> C;
    C.reserve(n);
    for (int i = 0; i < n; i++) {
        C[B[A[i]]] = A[i];
        B[A[i]] --;
    }
    for (auto v : C) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}