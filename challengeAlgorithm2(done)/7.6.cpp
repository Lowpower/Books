#include <climits>
#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& A, int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    long long cnt = 0;
    vector<int> L;
    vector<int> R;
    for (int i = 0; i < n1; i++) {
        L.push_back(A[left + i]);
    }
    for (int i = 0; i < n2; i++) {
        R.push_back(A[mid + i]);
    }
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    int l = 0;
    int r = 0;
    for (int i = left; i < right; i++) {
        if (L[l] <= R[r]) {
            A[i] = L[l++];
        } else {
            A[i] = R[r++];
            cnt += n1 - l;
        }
    }
    return cnt;
}

long long mergeSort(vector<int> &A, int n, int left, int right) {
    int mid;
    long long v1, v2, v3;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        v1 = mergeSort(A, n, left, mid);
        v2 = mergeSort(A, n, mid, right);
        v3 = merge(A, n, left, mid, right);
        return v1 + v2 + v3;
    } else {
        return 0;
    }
}

int main() {
    vector<int> A;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    long long ans = mergeSort(A, n, 0, n);
    cout << ans << endl;
    return 0;
}