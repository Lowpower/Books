#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
vector<int> G;
long long cnt;

void insertionSort(vector<int>& A, int g) {
    for(int i = g; i < A.size(); i++) {
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(vector<int>& A) {
    for(int h = 1;;) {
        if (h > A.size()) {
            break;
        }
        G.push_back(h);
        h = 3*h +1;
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(A, G[i]);
    }
}

int main() {
    int n;
    cin >> n;
    int tmp;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    int cnt = 0;
    shellSort(A);
    cout << G.size() << endl;
    for (int i = G.size()-1; i >= 0;i--) {
        cout << G[i];
        if(i) {
            cout << " ";
        }
    }
    cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
    return 0;
}