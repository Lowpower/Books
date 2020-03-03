#include <iostream>
#include <vector>
using namespace std;

struct Card {
    char suit;
    int value;
};

void merge(vector<Card>& A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<Card> L;
    vector<Card> R;
    for(int i = 0; i < n1; i++) {
        L.push_back(A[left+i]);
    }
    for (int i = 0; i < n2; i++) {
        R.push_back(A[mid +i]);
    }
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++) {
        if(L[i].value <= R[k].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<Card>& A, int left, int right) {
    int mid;
    if(left +1 < right) {
        mid = (left + right) /2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(vector<Card>& A, int p, int r) {
    Card x = A[r];
    int i = p-1;
    for(int j = p; j < r; j++) {
        if(A[j].value <= x.value) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(vector<Card>& A, int p, int r) {
    int q;
    if(p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main() {
    int n;
    cin >> n;
    string S;
    int tmp;
    vector<Card> A;
    vector<Card> B;
    for (int i = 0; i < n; i++) {
        cin >> S >> tmp;
        Card x{S[0], tmp};
        A.push_back(x);
        B.emplace_back(x);
    }
    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);

    int stable = 1;
    for (int i = 0; i < n; i++) {
        if(A[i].suit != B[i].suit) {
            stable = 0;
        }
    }
    if(stable == 1) {
        cout << "Stable" << endl;
    } else {
        cout << "Not Stable" << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << B[i].suit << " " << B[i].value << endl;
    }

    return 0;
}