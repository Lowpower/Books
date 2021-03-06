#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int cnt = 0;

void merge(vector<int>& A, int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L;
    vector<int> R;
    for (int i = 0; i < n1; i++) {
        L.push_back(A[left+i]);
    }
    for (int i = 0; i < n2; i++) {
        R.push_back(A[mid + i]);
    }
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    int l = 0, r = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if(L[l] <= R[r]) {
            A[k] = L[l++];
        } else {
            A[k] = R[r++];
        }
    }
}

void mergeSort(vector<int>& A, int n, int left, int right) {
    if(left +1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main() {
    int n;
    vector<int> A;
    cin >> n;
    A.reserve(n);
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    mergeSort(A, n, 0, n);
    for (int i = 0; i < n; i++) {
        if(i) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}