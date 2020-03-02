#include <iostream>
#include <vector>
using namespace std;
vector<int> A;

int partition(int p, int r) {
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r; j++) {
        if(A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

int main () {
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    int q = partition(0, n-1);
    for (int i = 0; i < n; i++) {
        if(i) {
            cout << "   ";
        }
        if(i == q) {
            cout << "[";
        }
        cout << A[i];
        if(i == q) {
            cout << "]";
        }
    }
    cout << endl;
    return 0;
}