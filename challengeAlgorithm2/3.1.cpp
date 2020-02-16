#include <iostream>
#include <vector>

using namespace std;

void trace(const vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        if(i > 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void insertionSort (vector<int>& A) {
    int v;
    for (int i = 1; i < A.size(); i++) {
        v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A;
    A.reserve(N + 1);
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    //trace(A);
    insertionSort(A);
    return 0;
}