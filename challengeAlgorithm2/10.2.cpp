#include <iostream>

using namespace std;
#define MAX 2000000
int A[MAX+1];
int h;

void maxHeapify (int i) {
    int l, r, larger;
    l = 2*i;
    r = 2*i +1;
    if (l <= h && A[l] > A[i]) {
        larger = l;
    } else {
        larger = i;
    }
    if (r <= h && A[r] > A[larger]) {
        larger = r;
    }
    if (larger != i) {
        swap(A[i], A[larger]);
        maxHeapify(larger);
    }
}

int main() {
    cin >> h;
    for (int i = 1; i <= h; i++) {
        cin >>A[i];
    }
    for (int i = h/2; i>=1 ;i--) {
        maxHeapify(i);
    }
    for (int i = 1; i<= h; i++) {
        cout << " " << A[i];
    }
    cout << endl;
    return 0;
}